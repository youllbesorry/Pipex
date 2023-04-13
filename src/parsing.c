/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:11:04 by bfaure            #+#    #+#             */
/*   Updated: 2023/04/13 13:01:03 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

char	*get_valid_paths(t_data *data, char **cmd)
{
	char		*pathname;
	size_t		i;

	i = 0;
	if (cmd[0] && access(cmd[0], X_OK) == 0)
		return (cmd[0]);
	while (data->paths[i])
	{
		pathname = ft_strjoin(data->paths[i], cmd[0]);
		if (!pathname)
			return (NULL);
		if (access(pathname, X_OK) == 0)
			return (pathname);
		free(pathname);
		i++;
	}
	return (NULL);
}

void	get_cmd_path(t_data *data)
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

void	get_path(char **env, t_data *data)
{
	ssize_t	i;

	i = -1;
	while (env[++i])
	{
		if (ft_strnstr(env[i], "PATH=", 5) != NULL)
		{
			data->path = ft_strnstr(env[i], "PATH=", 5);
			break ;
		}
	}
	if (!data->path)
	{
		close_fd(data);
		exit(0);
	}
	data->path += 5;
	data->paths = ft_split(data->path, ':');
	if (!data->paths)
	{
		close_fd(data);
		exit(0);
	}
	get_cmd_path(data);
	return ;
}
