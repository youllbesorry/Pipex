/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:39:41 by bfaure            #+#    #+#             */
/*   Updated: 2023/03/17 13:09:58 by bfaure           ###   ########lyon.fr   */
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
	get_path(env, argv, &data);
	close_fd(&data);
	free_tab(data.paths);
	return (0);
}
