/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:11:04 by bfaure            #+#    #+#             */
/*   Updated: 2023/02/22 23:42:01 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	get_path(char **env, char **argv, t_data data)
{
	size_t	i;
	int		len;
	ssize_t	nb_line;
	char	*pathname;
	int		j;
	int		k;

	i = 0;
	len = 0;
	nb_line = 0;
	//(void)argv;
	//data.valid_paths = NULL;
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
			data.paths[i] = ft_strfjoin(data.paths[i], "/");
			if (!data.paths[i])
				return (free_tab_error(data.paths, nb_line));
		}
		ft_printf("data.paths = %s\n", data.paths[i]);
		i++;
	}
	i = 0;
	k = 0;
	while (data.paths[i])
	{
		j = 1;
		while (argv[j])
		{
			ft_printf("data.paths[i] = %s\n", data.paths[i]);
			pathname = ft_strjoin(data.paths[i], argv[j]);
			ft_printf("argv = %s\n", argv[j]);
			ft_printf("pathname = %s\n", pathname);
			ft_printf("access = %i\n", access(pathname, F_OK));
			if (access(pathname, F_OK) == 0)
			{
				ft_printf("test\n");
				data.valid_paths[k] = ft_strjoin(data.paths[i], argv[j]);
				ft_printf("valide path = %s\n", data.valid_paths[k]);
				k++;
			}
			free(pathname);
			ft_printf("pathname2 = %s\n", pathname);
			j++;
		}
		i++;
	}
	free_tab(data.paths);
	ft_printf("pass\n");
	return ;
}
