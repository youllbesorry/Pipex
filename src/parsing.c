/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:11:04 by bfaure            #+#    #+#             */
/*   Updated: 2023/03/01 17:08:43 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

size_t	get_valid_paths(char **argv, t_data *data, size_t i, size_t j)
{
	static size_t	k = 0;
	char			*pathname;
	char			**cmd;

	if (ft_strchr(argv[j], ' ') != NULL)
	{
		cmd = ft_split(argv[j], ' ');
		ft_printf("argv = %s\n", argv[j]);
		if (!cmd)
			return (0);
		pathname = ft_strjoin(data->paths[i], cmd[0]);
		if (!pathname)
			return (0);
		free_tab(cmd);
	}
	else
		pathname = ft_strjoin(data->paths[i], argv[j]);
	if (!pathname)
		return (0);
	if (access(pathname, F_OK) == 0)
	{
		ft_printf("k = %i\n", k);
		data->valid_paths[k] = ft_strdup(pathname);
		if (!data->valid_paths[k])
			return (free_tab_error(data->valid_paths, k), 0);
		ft_printf("valid_path[%i] = %s\n", k, data->valid_paths[k]);
		data->arg[k] = ft_strdup(argv[j]);
		if (!data->arg[k])
			return (free_tab_error(data->arg, k), 0);
		ft_printf("arg[%i] = %s\n", k, data->arg[k]);
		k++;
	}
	free(pathname);
	return (k);
}

void	loop_on_paths(char **argv, t_data *data)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	data->arg = malloc((sizeof(char *)) * (data->v_paths_len + 1));
	if (!data->arg)
		return ;
	while (data->paths[i])
	{
		j = 1;
		while (argv[j])
		{
			k = get_valid_paths(argv, data, i, j);
			j++;
		}
		i++;
	}
	data->valid_paths[k] = "\0";
	return ;
}

int	get_valid_path_memory(char **argv, t_data *data)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*pathname;

	i = 0;
	k = 0;
	while (data->paths[i])
	{
		j = 1;
		while (argv[j])
		{
			pathname = ft_strjoin(data->paths[i], argv[j]);
			if (access(pathname, F_OK) == 0)
				k++;
			free(pathname);
			j++;
		}
		i++;
	}
	data->valid_paths = malloc((sizeof(char *)) * (k + 1));
	if (!data->valid_paths)
		return (0);
	data->v_paths_len = k;
	return (data->v_paths_len);
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
	if (get_valid_path_memory(argv, data) == 0)
		return ;
	loop_on_paths(argv, data);
	if (!data->valid_paths)
		return ;
	ft_printf("Paths OK\n");
	return ;
}
