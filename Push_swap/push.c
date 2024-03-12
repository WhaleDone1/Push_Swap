/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarpent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 09:10:34 by bcarpent          #+#    #+#             */
/*   Updated: 2024/03/12 09:38:29 by bcarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"


void	push_a(t_list **stack_head_a, t_list **stack_head_b)
{
	t_list *new_top;

	if (!stack_head_a || !stack_head_b || !*stack_head_b)
		return;
	new_top = *stack_head_b;
	*stack_head_b = (*stack_head_b)->next;
	new_top->next = *stack_head_a;
	*stack_head_a = new_top;
}

void	push_b(t_list **stack_head_a, t_list **stack_head_b)
{
	t_list *new_top;

	if (!stack_head_a || !stack_head_b || !*stack_head_a)
		return;
	new_top = *stack_head_a;
	*stack_head_a = (*stack_head_a)->next;
	new_top->next = *stack_head_b;
	*stack_head_b = new_top;
}

