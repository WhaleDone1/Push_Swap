/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarpent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 09:11:35 by bcarpent          #+#    #+#             */
/*   Updated: 2024/03/12 16:27:18 by bcarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

void	swap_a(t_list **stack_head_a)
{
	t_list *current;
	t_list *next;
	int tmp_data;

	if (!stack_head_a || !*stack_head_a || !(*stack_head_a)->next)
		return;
	current = *stack_head_a;
	next = current->next;
	tmp_data = current->data;
	current->data = next->data;
	next->data = tmp_data;
}

void	swap_b(t_list **stack_head_b)
{
	t_list *current;
	t_list *next;
	int tmp_data;

	if (!stack_head_b || !*stack_head_b || !(*stack_head_b)->next)
		return;
	current = *stack_head_b;
	next = current->next;
	tmp_data = current->data;
	current->data = next->data;
	next->data = tmp_data;
}

void	swap_a_and_b(t_list **stack_head_a, t_list **stack_head_b)
{
	if (!stack_head_a || !*stack_head_a || !stack_head_b || !*stack_head_b)
		return;

	swap_a(stack_head_a);
	swap_b(stack_head_b);
}

