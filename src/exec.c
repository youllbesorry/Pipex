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

//#include "../header/pipex.h"
# include <unistd.h>
# include <stdio.h>

int	main(int argc, char **argv, char **env)
{
	(void)argc;

	if (execve("/usr/bin/ls", argv, env) == -1)
		perror("Could not execve");
	return (0);
}
