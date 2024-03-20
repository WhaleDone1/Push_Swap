/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarpent <bcarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:39:57 by barpent           #+#    #+#             */
/*   Updated: 2024/03/20 16:30:11 by bcarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

static void	prepare_a(t_list **stack_a, t_list *cheapest_node, long stack_a_len)
{
	if (cheapest_node->index <= (stack_a_len / 2))
	{
		while ((*stack_a)->data != cheapest_node->data)
			rotate_a(stack_a, 1);
	}
	else
		while ((*stack_a)->data != cheapest_node->data)
			reverse_rotate_a(stack_a, 1);
}

static void	prepare_b(t_list **stack_a, t_list *cheapest_node, long stack_a_len)
{
	if (cheapest_node->target->index <= (stack_a_len / 2))
	{
		while ((*stack_a)->data != cheapest_node->target->data)
			rotate_b(stack_a, 1);
	}
	else
		while ((*stack_a)->data != cheapest_node->target->data)
			reverse_rotate_b(stack_a, 1);
}

void	prepare_move_a(t_list **stack_a, t_list **stack_b)
{
	long	stack_a_len;
	long	stack_b_len;
	t_list	*cheapest_node;

	cheapest_node = find_cheapest_cost(*stack_a);
	stack_a_len = list_len(*stack_a);
	stack_b_len = list_len(*stack_b);
	if (cheapest_node->index <= (stack_a_len / 2)
		&& cheapest_node->target->index <= (stack_b_len / 2))
		move_rotate_a_and_b(stack_a, stack_b, cheapest_node);
	else if (cheapest_node->index > (stack_a_len / 2)
		&& cheapest_node->target->index > (stack_b_len / 2))
		move_reverse_rotate_a_and_b(stack_a, stack_b, cheapest_node);
	prepare_a(stack_a, cheapest_node, stack_a_len);
	prepare_b(stack_b, cheapest_node, stack_b_len);
	push_b(stack_a, stack_b);
}

/*void	prepare_move_b(t_list **stack_a, t_list **stack_b)
{
	long	stack_a_len;
	long	stack_b_len;
	t_list	*cheapest_node;

	cheapest_node = find_cheapest_cost(*stack_b);
	stack_a_len = list_len(*stack_a);
	stack_b_len = list_len(*stack_b);
	if (cheapest_node->index <= (stack_b_len / 2)
		&& cheapest_node->target->index <= (stack_a_len / 2))
		move_rotate_a_and_b(stack_b, stack_a, cheapest_node);
	else if (cheapest_node->index > (stack_b_len / 2)
		&& cheapest_node->target->index > (stack_a_len / 2))
		move_reverse_rotate_a_and_b(stack_b, stack_a, cheapest_node);
	prepare_a(stack_b, cheapest_node, stack_b_len);
	prepare_b(stack_a, cheapest_node, stack_a_len);
	push_a(stack_a, stack_b);
}*/
