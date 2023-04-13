/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:29:09 by bfaure            #+#    #+#             */
/*   Updated: 2023/04/13 14:34:45 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <unistd.h>

typedef struct s_data
{
	pid_t	pid1;
	pid_t	pid2;
	char	**env;
	char	*path;
	int		fd[2];
	char	**paths;
	int		fd_infile;
	int		fd_outfile;
}	t_data;

#endif