/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barpent <barpent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 09:10:56 by bcarpent          #+#    #+#             */
/*   Updated: 2024/03/15 17:20:25 by barpent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"
#include "../Printf/ft_printf.h"

void reverse_rotate_a(t_list **stack_head_a, int rra)
{

	t_list *last;
	t_list *before_last = NULL;

	if (!stack_head_a || !*stack_head_a || !(*stack_head_a)->next)
		return;
	last = *stack_head_a;
	while (last->next != NULL)
	{
		before_last = last;
		last = last->next;
	}
	last->next = *stack_head_a;
	*stack_head_a = last;
	before_last->next = NULL;
	if (rra == 1)
		ft_printf("rra\n");
}

void reverse_rotate_b(t_list **stack_head_b, int rrb)
{

	t_list *last;
	t_list *before_last;

	if (!stack_head_b || !*stack_head_b || !(*stack_head_b)->next)
		return;
	last = *stack_head_b;
	while (last->next != NULL)
	{
		before_last = last;
		last = last->next;
	}
	last->next = *stack_head_b;
	*stack_head_b = last;
	before_last->next = NULL;
	if (rrb == 1)
		ft_printf("rrb\n");
}

void reverse_rotate_a_and_b(t_list **stack_head_a, t_list **stack_head_b)
{
	if (!stack_head_a || !*stack_head_a || !(*stack_head_a)->next)
		return;
	reverse_rotate_a(stack_head_a, 0);
	reverse_rotate_b(stack_head_b, 0);
	ft_printf("rrr\n");
}

void move_reverse_rotate_a_and_b(t_list **stack_head_a, t_list **stack_head_b, t_list *cheapest)
{
	while ((*stack_head_a)->data != cheapest->data && (*stack_head_b)->data != cheapest->target->data)
		reverse_rotate_a_and_b(stack_head_a, stack_head_b);
}
