/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:21:31 by bfaure            #+#    #+#             */
/*   Updated: 2023/03/15 09:36:02 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	init_data(t_data *data)
{
	data->pid1 = 0;
	data->pid2 = 0;
	data->fd[0] = 0;
	data->fd[1] = 0;
	data->env = NULL;
	data->path = NULL;
	data->paths = NULL;
	data->fd_infile = 0;
	data->fd_outfile = 0;
	data->valid_paths = NULL;
}
