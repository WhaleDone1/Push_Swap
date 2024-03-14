/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barpent <barpent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 09:11:15 by bcarpent          #+#    #+#             */
/*   Updated: 2024/03/14 10:44:37 by barpent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

void rotate_a(t_list **stack_head_a)
{
	t_list *tmp_ptr;

	if (!stack_head_a || !*stack_head_a || !(*stack_head_a)->next)
		return;
	tmp_ptr = *stack_head_a;
	while (tmp_ptr->next != NULL)
		tmp_ptr = tmp_ptr->next;
	tmp_ptr->next = *stack_head_a;
	*stack_head_a = (*stack_head_a)->next;
	tmp_ptr = tmp_ptr->next;
	tmp_ptr->next = NULL;
}

void rotate_b(t_list **stack_head_b)
{
	t_list *tmp_ptr;

	if (!stack_head_b || !*stack_head_b || !(*stack_head_b)->next)
		return;
	tmp_ptr = *stack_head_b;
	while (tmp_ptr->next != NULL)
		tmp_ptr = tmp_ptr->next;
	tmp_ptr->next = *stack_head_b;
	*stack_head_b = (*stack_head_b)->next;
	tmp_ptr = tmp_ptr->next;
	tmp_ptr->next = NULL;
}

void rotate_a_and_b(t_list **stack_head_a, t_list **stack_head_b)
{
	if (!stack_head_a || !*stack_head_a || !stack_head_b || !*stack_head_b)
		return;
	rotate_a(stack_head_a);
	rotate_b(stack_head_b);
}

void move_rotate_a_and_b(t_list **stack_head_a, t_list **stack_head_b, t_list *cheapest)
{
	while ((*stack_head_a)->data != cheapest->data && (*stack_head_b)->data != cheapest->target->data)
		rotate_a_and_b(stack_head_a, stack_head_b);
}
