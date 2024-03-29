/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:39:41 by bfaure            #+#    #+#             */
/*   Updated: 2023/04/12 15:05:46 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	if (argc != 5)
	{
		ft_printf(RED"ERROR\nYou must give 5 arg to the program\n"END);
		exit (0);
	}
	init_data(&data);
	data.env = env;
	check_open_file(argv[1], argv[argc - 1], &data);
	get_path(env, &data);
	exec(&data, argv, env);
	close_fd(&data);
	waitpid(data.pid1, NULL, 0);
	waitpid(data.pid2, NULL, 0);
	free_tab(data.paths);
	return (0);
}
