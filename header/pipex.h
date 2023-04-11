/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:40:52 by bfaure            #+#    #+#             */
/*   Updated: 2023/04/11 19:03:41 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "struct.h"
# include "sys/wait.h"
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>
# include "../Libft/headers/libft.h"
# include "../Libft/headers/ft_printf.h"

void	get_path(char **env, t_data *data);
void	init_data(t_data *data);
void	check_open_file(char *infile, char *outfile, t_data *data);
void	free_tab_error(char **tab, size_t len);
void	free_tab(char **tab);
int		exec(t_data *data, char **argv, char **env);
void	close_fd(t_data *data);
void	get_cmb_path(t_data *data);
void	loop_on_paths(char **argv, t_data *data);
char	*get_valid_paths(t_data *data, char **cmd);

#endif