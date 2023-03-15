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

static void	dup_cmd1(t_data *data)
{
	if (dup2(data->fd[1], STDOUT_FILENO) == -1)
	{
		ft_printf("test dup1\n");
		close(data->fd[1]);
		perror("ERROR\nCould not create dup");
		exit(3);
	}
	if (dup2(data->fd_infile, STDIN_FILENO) == -1)
	{
		close(data->fd_infile);
		perror("ERROR\nCould not create dup");
		exit(3);
	}	
}

static void	dup_cmd2(t_data *data)
{
	if (dup2(data->fd[0], STDIN_FILENO) == -1)
	{
		ft_printf("test dup1\n");
		close(data->fd[0]);
		perror("ERROR\nCould not create dup");
		exit(3);
	}
	if (dup2(data->fd_outfile, STDOUT_FILENO) == -1)
	{
		close(data->fd_outfile);
		perror("ERROR\nCould not create dup");
		exit(3);
	}
}

int	exec(t_data *data, char **cmd, int k)
{
	if (k == 0)
	{
		data->pid1 = fork();
		if (data->pid1 == 0)
		{
			dup_cmd1(data);
			ft_printf("test pid1\n");
			if (execve(data->valid_paths, cmd, data->env) == -1)
				perror("ERROR\nCould not execve\n");
		}
	}
	if (k == 1)
	{
		data->pid2 = fork();
		if (data->pid2 == 0)
		{
			dup_cmd2(data);
			ft_printf("test pid2\n");
			if (execve(data->valid_paths, cmd, data->env) == -1)
				perror("ERROR\nCould not execve\n");
		}
	}
	return (0);
}
