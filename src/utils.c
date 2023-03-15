/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:03:43 by bfaure            #+#    #+#             */
/*   Updated: 2023/03/15 09:58:16 by bfaure           ###   ########lyon.fr   */
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

void	free_tab_error(char **tab, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		free(tab[i]);
		i++;
	}
	if (len != 0)
		free(tab);
	return ;
}

void	check_open_file(char *infile, char *outfile, t_data *data)
{
	data->fd_infile = open(infile, O_RDONLY);
	if (data->fd_infile == -1)
	{
		perror("ERROR\nCould not open infile");
		exit(1);
	}
	data->fd_outfile = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->fd_outfile == -1)
	{
		perror("ERROR\nCould not open outfile");
		exit(1);
	}
}
