/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarpent <bcarpent@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 09:25:06 by bcarpent          #+#    #+#             */
/*   Updated: 2024/03/20 11:31:58 by bcarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"
#include "../Printf/ft_printf.h"

static void	put_min_on_top(t_list **a)
{
	t_list	*min;

	min = find_smallest_nb(*a);
	if (min->index <= list_len(*a) / 2)
		while ((*a)->data != min->data)
			rotate_a(a, 1);
	else
		while ((*a)->data != min->data)
			reverse_rotate_a(a, 1);
}

void	sort_three(t_list **stack_head_a)
{
	t_list	*biggest_nb_node;

	biggest_nb_node = find_biggest_nb(*stack_head_a);
	if (biggest_nb_node->index == 0)
		rotate_a(stack_head_a, 1);
	else if (biggest_nb_node->index == 1)
		reverse_rotate_a(stack_head_a, 1);
	if (is_stack_sorted(*stack_head_a) == 0)
		swap_a(stack_head_a, 1);
}

void	sort_stack(t_list **stack_head_a, t_list **stack_head_b)
{
	int	stack_a_len;

	stack_a_len = (list_len(*stack_head_a));
	if (stack_a_len-- > 3 && (is_stack_sorted(*stack_head_a) == 0))
		push_b(stack_head_a, stack_head_b);
	if (stack_a_len-- > 3 && is_stack_sorted(*stack_head_a) == 0)
		push_b(stack_head_a, stack_head_b);
	while (stack_a_len > 3 && is_stack_sorted(*stack_head_a) == 0)
	{
		set_target_a(stack_head_a, *stack_head_b);
		sort_cost(*stack_head_a, *stack_head_b);
		prepare_move_a(stack_head_a, stack_head_b);
	}
	if (is_stack_sorted(*stack_head_a) == 0)
		sort_three(stack_head_a);
	while (*stack_head_b != NULL)
	{
		set_target_b(stack_head_b, *stack_head_a);
		sort_cost(*stack_head_b, *stack_head_a);
		prepare_move_b(stack_head_a, stack_head_b);
	}
	put_min_on_top(stack_head_a);
}
