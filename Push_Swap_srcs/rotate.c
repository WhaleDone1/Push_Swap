/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barpent <barpent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 09:11:15 by bcarpent          #+#    #+#             */
/*   Updated: 2024/03/15 17:16:57 by barpent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"
#include "../Printf/ft_printf.h"

void rotate_a(t_list **stack_head_a, int ra)
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
	if (ra == 1)
		ft_printf("ra\n");
}

void rotate_b(t_list **stack_head_b, int rb)
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
	if (rb == 1)
		ft_printf("rb\n");
}

void rotate_a_and_b(t_list **stack_head_a, t_list **stack_head_b)
{
	if (!stack_head_a || !*stack_head_a || !stack_head_b || !*stack_head_b)
		return;
	rotate_a(stack_head_a, 0);
	rotate_b(stack_head_b, 0);
	ft_printf("rr\n");
}

void move_rotate_a_and_b(t_list **stack_head_a, t_list **stack_head_b, t_list *cheapest)
{
	while ((*stack_head_a)->data != cheapest->data && (*stack_head_b)->data != cheapest->target->data)
		rotate_a_and_b(stack_head_a, stack_head_b);
}
