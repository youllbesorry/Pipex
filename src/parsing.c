/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:11:04 by bfaure            #+#    #+#             */
/*   Updated: 2023/02/27 21:17:28 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	get_valid_path(char **argv, t_data *data, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*pathname;

	i = 0;
	k = 0;
	data->valid_paths = malloc((sizeof(char *)) * (len + 1));
	if (!data->valid_paths)
		return ;
	while (data->paths[i])
	{
		j = 1;
		while (argv[j])
		{
			pathname = ft_strjoin(data->paths[i], argv[j]);
			if (access(pathname, F_OK) == 0)
			{
				data->valid_paths[k] = ft_strjoin(data->paths[i], argv[j]);
				if (!data->valid_paths[k])
					return (free_tab_error(data->valid_paths, k));
				ft_printf("valide_path[%i] = %s\n", k, data->valid_paths[k]);
				k++;
			}
			free(pathname);
			j++;
		}
		i++;
	}
	data->valid_paths[k] = "\0";
	ft_printf("get_valid_path OK\n");
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
	data->v_paths_len = k;
	ft_printf("get_valid_path_memory OK\n");
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
			ft_printf("data->paths[%i] = %s\n", i, data->paths[i]);
		}
		i++;
	}
	ft_printf("get_cmp_path OK\n");
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
	get_valid_path(argv, data, data->v_paths_len);
	if (!data->valid_paths)
		return ;
	ft_printf("Paths OK\n");
	return ;
}
