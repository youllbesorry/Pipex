/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:39:41 by bfaure            #+#    #+#             */
/*   Updated: 2023/03/14 10:45:06 by bfaure           ###   ########lyon.fr   */
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
	data.env = env;
	get_path(env, argv, &data);
	free_tab(data.paths);
	return (0);
}
