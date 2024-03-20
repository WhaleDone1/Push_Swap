/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barpent <barpent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 09:10:56 by bcarpent          #+#    #+#             */
/*   Updated: 2024/03/20 11:54:30 by bcarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"
#include "../Printf/ft_printf.h"

void	reverse_rotate_a(t_list **stack_head_a, int rra)
{
	t_list	*last_node;
	t_list	*before_last_node;

	if (!stack_head_a || !*stack_head_a || !(*stack_head_a)->next)
		return ;
	last_node = *stack_head_a;
	while (last_node->next != NULL)
	{
		before_last_node = last_node;
		last_node = last_node->next;
	}
	last_node->next = *stack_head_a;
	*stack_head_a = last_node;
	before_last_node->next = NULL;
	set_index(stack_head_a);
	if (rra == 1)
		ft_printf("rra\n");
}

void	reverse_rotate_b(t_list **stack_head_b, int rrb)
{
	t_list	*last_node;
	t_list	*before_last_node;

	if (!stack_head_b || !*stack_head_b || !(*stack_head_b)->next)
		return ;
	last_node = *stack_head_b;
	while (last_node->next != NULL)
	{
		before_last_node = last_node;
		last_node = last_node->next;
	}
	last_node->next = *stack_head_b;
	*stack_head_b = last_node;
	before_last_node->next = NULL;
	set_index(stack_head_b);
	if (rrb == 1)
		ft_printf("rrb\n");
}

void	reverse_rotate_a_and_b(t_list **stack_head_a, t_list **stack_head_b)
{
	if (!stack_head_a || !*stack_head_a || !(*stack_head_a)->next)
		return ;
	reverse_rotate_a(stack_head_a, 0);
	reverse_rotate_b(stack_head_b, 0);
	ft_printf("rrr\n");
}

void	move_reverse_rotate_a_and_b(t_list **stack_head_a,
		t_list **stack_head_b, t_list *cheapest_node)
{
	while ((*stack_head_a)->data != cheapest_node->data
		&& (*stack_head_b)->data != cheapest_node->target->data)
		reverse_rotate_a_and_b(stack_head_a, stack_head_b);
}
