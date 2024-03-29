/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:10:29 by bfaure            #+#    #+#             */
/*   Updated: 2023/04/13 15:13:08 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return ;
}

void	free_and_close_all(t_data *data)
{
	close_fd(data);
	if (data->paths)
		free_tab(data->paths);
	return ;
}

void	check_open_file(char *infile, char *outfile, t_data *data)
{
	data->fd_infile = open(infile, O_RDONLY);
	if (data->fd_infile == -1)
	{
		perror(RED"ERROR\nCould not open infile"END);
		exit(0);
	}
	data->fd_outfile = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->fd_outfile == -1)
	{
		perror(RED"ERROR\nCould not open outfile"END);
		close(data->fd_infile);
		exit(0);
	}
}

void	close_fd(t_data *data)
{
	if (data->fd[0])
		close(data->fd[0]);
	if (data->fd[1])
		close(data->fd[1]);
	if (data->fd_infile)
		close(data->fd_infile);
	if (data->fd_outfile)
		close(data->fd_outfile);
	return ;
}

void	call_perror(t_data	*data, char **cmd)
{
	perror(RED"CMD"END);
	free_tab(data->paths);
	free_tab(cmd);
	exit(1);
}
