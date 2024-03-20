/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barpent <barpent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 04:14:36 by barpent           #+#    #+#             */
/*   Updated: 2024/03/20 11:09:01 by bcarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

void	ft_free_list(t_list **list)
{
	if (*list == NULL)
		return ;
	if ((*list)->next != NULL)
		ft_free_list((&(*list)->next));
	free(*list);
	*list = NULL;
}

void	ft_free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	if (str)
		free(str);
}
