/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:40:52 by bfaure            #+#    #+#             */
/*   Updated: 2023/02/22 21:48:10 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PIPEX_H
# define PIPEX_H

# include "struct.h"
# include <fcntl.h>
# include <errno.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include "../Libft/headers/libft.h"
# include "../Libft/headers/ft_printf.h"
# include "../Libft/headers/get_next_line.h"

void	get_path(char **env, char **argc, t_data data);
void	free_tab_error(char **tab, size_t len);
void	free_tab(char **tab);

#endif