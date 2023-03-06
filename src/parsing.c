/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:11:04 by bfaure            #+#    #+#             */
/*   Updated: 2023/03/06 17:00:01 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"


char	**add_infile_content(char **argv, char **cmd, size_t j)
{
	static size_t	i = 0;
	char			*launch_arg;
	char			*save;
	char			*line;
	int				fd;

	if (i == 0)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (cmd);
		line = get_next_line(fd);
		if (!line)
			return (cmd);
		save = ft_strjoin(" ", line);
		launch_arg = ft_strjoin(argv[j], save);
		ft_printf("launch_arg = %s\n", launch_arg);
		free_tab(cmd);
		cmd = ft_split(launch_arg, ' ');
		i = 1;
		free(line);
		free(save);
		free(launch_arg);
		return (cmd);
	}
	return (cmd);
}

void	get_valid_paths(char **argv, t_data *data, size_t i, size_t j)
{
	static int	k = 0;
	char		*pathname;
	char		**cmd;

	cmd = ft_split(argv[j], ' ');
	if (!cmd)
		return ;
	pathname = ft_strjoin(data->paths[i], cmd[0]);
	if (!pathname)
		return ;
	if (access(pathname, F_OK) == 0 && k < 2)
	{
		data->valid_paths = ft_strdup(pathname);
		if (!data->valid_paths)
			return ;
		ft_printf("valid_path = %s\n", data->valid_paths);
		cmd = add_infile_content(argv, cmd, j);
		exec(data, cmd);
		free(data->valid_paths);
		k++;
	}
	free_tab(cmd);
	free(pathname);
	return ;
}

void	loop_on_paths(char **argv, t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (data->paths[i])
	{
		j = 1;
		while (argv[j])
		{
			get_valid_paths(argv, data, i, j);
			j++;
		}
		i++;
	}
	wait(NULL);
	return ;
}

void	get_cmb_path(t_data *data)
{
	size_t	i;
	size_t	nb_line;
	size_t	len;

	i = 0;
	nb_line = ft_cont_word(data->path, ':');
	while (data->paths[i])
	{
		len = ft_strlen(data->paths[i]);
		if (data->paths[i][len - 1] != '/')
		{
			data->paths[i] = ft_strfjoin(data->paths[i], "/");
			if (!data->paths[i])
				return (free_tab_error(data->paths, nb_line));
		}
		i++;
	}
	return ;
}

void	get_path(char **env, char **argv, t_data *data)
{
	size_t	i;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5) != NULL)
		{
			data->path = ft_strnstr(env[i], "PATH=", 5);
			break ;
		}
		i++;
	}
	data->path += 5;
	data->paths = ft_split(data->path, ':');
	if (!data->paths)
		return ;
	get_cmb_path(data);
	loop_on_paths(argv, data);
	if (!data->valid_paths)
		return ;
	ft_printf("Paths OK\n");
	return ;
}
