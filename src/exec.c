/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:38:41 by bfaure            #+#    #+#             */
/*   Updated: 2023/02/23 10:38:41 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

int	exec(t_data *data, char **cmd)
{
	int	id;

	id = fork();
	if (id == 0)
	{
		if (execve(data->valid_paths, cmd, data->env) == -1)
			perror("Could not execve\n");
	}
	else
		wait(NULL);
	return (0);
}
