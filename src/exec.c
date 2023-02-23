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

int	test_exec(t_data data)
{
	char	*envp[] = { NULL };
	int i;

	i = 1;
	while (data.file[i])
	{
		ft_printf("data.file[%i] = %s\n", i, data.file[i]);
		i++;
	}
	if (execve(data.valid_paths[0], data.file, envp) == -1)
		perror("Could not execve");
	return (0);
}
