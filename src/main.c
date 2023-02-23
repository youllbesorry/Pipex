/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:39:41 by bfaure            #+#    #+#             */
/*   Updated: 2023/02/23 14:53:49 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	data.paths = NULL;
	if (argc < 2)
	{
		ft_printf("ERROR\nYou must give at least 5 arg to the program\n");
		exit (0);
	}
	get_path(env, argv, data, argc);
	return (0);
}