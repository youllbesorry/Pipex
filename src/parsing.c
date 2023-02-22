/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:11:04 by bfaure            #+#    #+#             */
/*   Updated: 2023/02/22 18:20:51 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	get_path(char **env, t_data data)
{
	size_t	i;
	int		len;
	ssize_t	nb_line;

	i = 0;
	len = 0;
	nb_line = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5) != NULL)
		{
			data.path = ft_strnstr(env[i], "PATH=", 5);
			break ;
		}
		i++;
	}
	data.path += 5;
	nb_line = ft_cont_word(data.path, ':');
	data.paths = ft_split(data.path, ':');
	if (!data.paths)
		return ;
	i = 0;
	while (data.paths[i])
	{
		len = ft_strlen(data.paths[i]);
		if (data.paths[i][len -1] != '/')
		{
			data.paths[i] = ft_strjoin(data.paths[i], "/");
			if (!data.paths[i])
				return (free_tab_error(data.paths, nb_line));
		}
		ft_printf("data.paths = %s\n", data.paths[i]);
		i++;
	}
	free_tab(data.paths);
	return ;
}
