/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:39:41 by bfaure            #+#    #+#             */
/*   Updated: 2023/03/15 11:56:41 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	if (argc < 5)
	{
		ft_printf("ERROR\nYou must give at least 5 arg to the program\n");
		exit (0);
	}
	init_data(&data);
	data.env = env;
	check_open_file(argv[1], argv[argc - 1], &data);
	if (pipe(data.fd) == -1)
	{
		perror("ERROR\nCould not create the pipe\n");
		exit(1);
	}
	get_path(env, argv, &data);
	waitpid(data.pid1, NULL, 0);
	waitpid(data.pid2, NULL, 0);
	free_tab(data.paths);
	return (0);
}
