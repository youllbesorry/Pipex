/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:39:41 by bfaure            #+#    #+#             */
/*   Updated: 2023/03/01 16:00:33 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	// data.paths = NULL;
	// data.valid_paths = NULL;
	//data.v_paths_len = 0;
	if (argc < 2)
	{
		ft_printf("ERROR\nYou must give at least 5 arg to the program\n");
		exit (0);
	}
	get_path(env, argv, &data);
	free_tab(data.paths);
	free_tab_error(data.valid_paths, data.v_paths_len);
	free_tab_error(data.arg, data.v_paths_len);
	return (0);
}
