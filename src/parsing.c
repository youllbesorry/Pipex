/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:11:04 by bfaure            #+#    #+#             */
/*   Updated: 2023/02/23 20:09:50 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	get_path(char **env, char **argv, t_data data, int argc)
{
	size_t	i;
	int		len;
	ssize_t	nb_line;
	char	*pathname;
	int		j;
	int		k;
	int		n;

	i = 0;
	len = 0;
	nb_line = 0;
	data.nb_cmd = 0;
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
		i++;
	}
	i = 0;
	k = 0;
	while (data.paths[i])
	{
		j = 1;
		while (argv[j])
		{
			pathname = ft_strjoin(data.paths[i], argv[j]);
			if (access(pathname, F_OK) == 0)
				data.nb_cmd++;
			free(pathname);
			j++;
		}
		i++;
	}
	data.valid_paths = malloc((sizeof (char *)) * data.nb_cmd);
	if (!data.valid_paths)
		return ;
	ft_printf("data.nb_cmf = %i\n", (data.nb_cmd / 2));
	data.cmd = malloc(sizeof(char *) * data.nb_cmd / 2);
	if (!data.cmd)
		return ;
	i = 0;
	k = 0;
	while (data.paths[i])
	{
		j = 1;
		while (argv[j])
		{
			pathname = ft_strjoin(data.paths[i], argv[j]);
			if (access(pathname, F_OK) == 0)
			{
				data.valid_paths[k] = ft_strjoin(data.paths[i], argv[j]);
				ft_printf("valide_path[%i] = %s\n", k, data.valid_paths[k]);
				if (k < (data.nb_cmd / 2))
				{
					data.cmd[k] = ft_strdup(argv[j]);
					ft_printf("data.cmd[%i] = %s\n", k, data.cmd[k]);
				}
				k++;
			}
			free(pathname);
			j++;
		}
		i++;
	}
	j = 1;
	data.file = malloc((sizeof (char *)) * (k / 2) + 1);
	if (!data.file)
		return ;
	data.file[0] = "r\n";
	i = 1;
	(void)argc;
	while (argv[j])
	{
		k = 0;
		n = 0;
		while (k < data.nb_cmd / 2)
		{
			if ((ft_strnstr(argv[j], data.cmd[k], ft_strlen(argv[j]))))
				n = 1;
			k++;
		}
		if (n != 1)
		{
			data.file[i] = ft_strdup(argv[j]);
			ft_printf("data.file[%i] = %s\n", i, data.file[i]);
			i++;
		}
		j++;
	}
	data.file[i] = '\0';
	test_exec(data);
	free_tab(data.paths);
	free_tab_error(data.valid_paths, k);
	//free_tab(data.file);
	ft_printf("pass\n");
	return ;
}
