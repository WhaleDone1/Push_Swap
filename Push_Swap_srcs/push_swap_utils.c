/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barpent <barpent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 09:15:55 by bcarpent          #+#    #+#             */
/*   Updated: 2024/03/20 11:12:24 by bcarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int	list_len(t_list *stack_head)
{
	int	i;

	i = 0;
	while (stack_head != NULL)
	{
		i++;
		stack_head = stack_head->next;
	}
	return (i);
}

t_list	*find_biggest_nb(t_list *stack_head)
{
	t_list	*biggest_nb;

	biggest_nb = stack_head;
	while (stack_head->next != NULL)
	{
		stack_head = stack_head->next;
		if (biggest_nb->data < stack_head->data)
			biggest_nb = stack_head;
	}
	return (biggest_nb);
}

t_list	*find_smallest_nb(t_list *stack_head)
{
	t_list	*smallest_nb;

	smallest_nb = stack_head;
	while (stack_head->next != NULL)
	{
		stack_head = stack_head->next;
		if (smallest_nb->data > stack_head->data)
			smallest_nb = stack_head;
	}
	return (smallest_nb);
}

t_list	*find_cheapest_cost(t_list *stack_head)
{
	t_list	*cheapest;

	cheapest = stack_head;
	stack_head = stack_head->next;
	while (stack_head)
	{
		if (stack_head->cost < cheapest->cost)
			cheapest = stack_head;
		stack_head = stack_head->next;
	}
	return (cheapest);
}

void	set_index(t_list **stack_head)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *stack_head;
	while (tmp != NULL)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
}
