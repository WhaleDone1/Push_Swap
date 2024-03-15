/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barpent <barpent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 09:11:35 by bcarpent          #+#    #+#             */
/*   Updated: 2024/03/15 17:13:49 by barpent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"
#include "../Printf/ft_printf.h"

void swap_a(t_list **stack_head_a, int sa)
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
	if (sa == 1)
		ft_printf("sa\n");
}

void swap_b(t_list **stack_head_b, int sb)
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
	if (sb == 1)
		ft_printf("sb\n");
}

void swap_a_and_b(t_list **stack_head_a, t_list **stack_head_b)
{
	if (!stack_head_a || !*stack_head_a || !stack_head_b || !*stack_head_b)
		return;

	swap_a(stack_head_a, 0);
	swap_b(stack_head_b, 0);
	ft_printf("ss\n");
}
