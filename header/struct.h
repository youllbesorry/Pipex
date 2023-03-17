/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:29:09 by bfaure            #+#    #+#             */
/*   Updated: 2023/03/17 11:47:55 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_data
{
	char	**env;
	char	*path;
	char	**paths;
	char	*valid_paths;
	int		pid1;
	int		pid2;
	int		fd[2];
	int		fd_infile;
	int		fd_outfile;
}	t_data;

#endif