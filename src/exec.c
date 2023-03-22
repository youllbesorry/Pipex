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

static void dup_cmd1(t_data *data)
{
	if (dup2(data->fd_infile, STDIN_FILENO) == -1)
	{
		free(data->valid_paths);
		perror("ERROR\nCould not create dup");
		close_fd(data);
		exit(1);
	}
	else
		close(data->fd_infile);
	if (dup2(data->fd[1], STDOUT_FILENO) == -1)
	{
		free(data->valid_paths);
		perror("ERROR\nCould not create dup");
		close_fd(data);
		exit(1);
	}
	else
		close(data->fd[1]);
}

static void dup_cmd2(t_data *data)
{
	if (dup2(data->fd[0], STDIN_FILENO) == -1)
	{
		free(data->valid_paths);
		perror("ERROR\nCould not create dup");
		close_fd(data);
		exit(1);
	}
	else
		close(data->fd[0]);
	if (dup2(data->fd_outfile, STDOUT_FILENO) == -1)
	{
		close(data->fd_outfile);
		free(data->valid_paths);
		perror("ERROR\nCould not create dup");
		close_fd(data);
		exit(1);
	}
	else
		close(data->fd_outfile);
}

int exec(t_data *data, char **cmd, int k)
{
	if (k == 0)
	{
		if (pipe(data->fd) == -1)
		{
			perror("ERROR\nCould not create the pipe\n");
			free_tab(cmd);
			close_fd(data);
			exit(1);
		}
		data->pid1 = fork();
		if (data->pid1 == 0)
		{
			if (data->fd[0])
				close(data->fd[0]);
			ft_printf("test\n");
			dup_cmd1(data);
			close_fd(data);
			execve(data->valid_paths, cmd, data->env);
			call_perror(data);
		}
		return (0);
	}
	data->pid2 = fork();
	if (data->pid2 == 0)
	{
		if (data->fd[1])
			close(data->fd[1]);
		dup_cmd2(data);
		close_fd(data);
		execve(data->valid_paths, cmd, data->env);
		call_perror(data);
	}
	waitpid(data->pid1, NULL, 0);
	waitpid(data->pid2, NULL, 0);
	return (0);
}
