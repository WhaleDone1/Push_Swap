/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barpent <barpent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 09:10:34 by bcarpent          #+#    #+#             */
/*   Updated: 2024/03/15 17:24:12 by barpent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"
#include "../Printf/ft_printf.h"

void push_a(t_list **stack_head_a, t_list **stack_head_b)
{
	t_list *new_top;

	if (!stack_head_a || !stack_head_b || !*stack_head_b)
		return;
	new_top = *stack_head_b;
	*stack_head_b = (*stack_head_b)->next;
	new_top->next = *stack_head_a;
	*stack_head_a = new_top;
	ft_printf("pa\n");
}

void push_b(t_list **stack_head_a, t_list **stack_head_b)
{
	t_list *new_top;

	if (!stack_head_a || !stack_head_b || !*stack_head_a)
		return;
	new_top = *stack_head_a;
	*stack_head_a = (*stack_head_a)->next;
	new_top->next = *stack_head_b;
	*stack_head_b = new_top;
	ft_printf("pb\n");
}
