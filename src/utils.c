/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:03:43 by bfaure            #+#    #+#             */
/*   Updated: 2023/02/25 22:17:47 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	free_tab(char **tab)
{
	size_t	i;

	i = 0;
	ft_printf("free_tab\n");
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
	ft_printf("free_tab_error\n");
	while (i < len)
	{
		ft_printf("tab[i] = %s\n", tab[i]);
		free(tab[i]);
		i++;
	}
	free(tab);
	return ;
}
