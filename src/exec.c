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
	if (dup2(data->fd_infile, STDIN_FILENO) == -1)
	{
		free_and_close_all(data);
		perror(RED"ERROR\nCould not create dup1 in"END);
		exit(1);
	}
	else
		close(data->fd_infile);
	if (dup2(data->fd[1], STDOUT_FILENO) == -1)
	{
		free_and_close_all(data);
		perror(RED"ERROR\nCould not create dup1 out"END);
		exit(1);
	}
	else
		close(data->fd[1]);
	return ;
}

static void	dup_cmd2(t_data *data)
{
	if (dup2(data->fd[0], STDIN_FILENO) == -1)
	{
		free_and_close_all(data);
		perror(RED"ERROR\nCould not create dup2 in"END);
		exit(0);
	}
	else
		close(data->fd[0]);
	if (dup2(data->fd_outfile, STDOUT_FILENO) == -1)
	{
		free_and_close_all(data);
		perror(RED"ERROR\nCould not create dup2 out"END);
		exit(1);
	}
	else
		close(data->fd_outfile);
	return ;
}

void	exec_cmd_1(t_data *data, char **argv, char **env)
{
	char	**cmd;
	char	*valid_path;

	if (data->fd[0])
		close(data->fd[0]);
	dup_cmd1(data);
	cmd = ft_split(argv[2], ' ');
	if (!cmd)
	{
		free_tab(cmd);
		free_and_close_all(data);
		exit(1);
	}
	valid_path = get_valid_paths(data, cmd);
	if (!valid_path)
	{
		free_tab(cmd);
		free_and_close_all(data);
		ft_putstr_fd(RED"ERROR\nCommand not 1 found\n"END, 2);
		exit(1);
	}
	close_fd(data);
	if (execve(valid_path, cmd, env) == -1)
		call_perror(data, cmd);
}

void	exec_cmd_2(t_data *data, char **argv, char **env)
{
	char	**cmd;
	char	*valid_path;

	if (data->fd[1])
		close(data->fd[1]);
	dup_cmd2(data);
	cmd = ft_split(argv[3], ' ');
	if (!cmd)
	{
		free_tab(cmd);
		free_and_close_all(data);
		exit(1);
	}
	valid_path = get_valid_paths(data, cmd);
	if (!valid_path)
	{
		free_tab(cmd);
		free_and_close_all(data);
		ft_putstr_fd(RED"ERROR\nCommand not 2 found\n"END, 2);
		exit(1);
	}
	close_fd(data);
	if (execve(valid_path, cmd, env) == -1)
		call_perror(data, cmd);
}

int	exec(t_data *data, char **argv, char **env)
{
	if (pipe(data->fd) < 0)
	{
		perror(RED"ERROR\nCould not create the pipe\n"END);
		close_fd(data);
		exit(1);
	}
	data->pid1 = fork();
	if (data->pid1 == 0)
		exec_cmd_1(data, argv, env);
	close(data->fd_infile);
	data->pid2 = fork();
	if (data->pid2 == 0)
		exec_cmd_2(data, argv, env);
	return (0);
}
