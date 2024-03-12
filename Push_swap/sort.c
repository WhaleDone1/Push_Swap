/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarpent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 09:25:06 by bcarpent          #+#    #+#             */
/*   Updated: 2024/03/12 14:22:56 by bcarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

void	sort_three(t_list **stack_head_a)
{
	t_list	*biggest_nb;

	biggest_nb = find_biggest_nb;
	if (biggest_nb == *stack_head_a)
		rotate_a(stack_head_a);
	else if ((*stack_head_a)->next == biggest_nb)
		reverse_rotate_a(stack_head_a);
	if ((*stack_head_a)->data > (*stack_head_a)->next->data)
		swap_a(stack_head_a);
}

void	sort_stack(t_list **stack_head_a, t_list **stack_head_b)
{
	int	stack_a_len;

	stack_a_len = list_len(*stack_head_a);
	if (stack_a_len > 3 && is_stack_sorted(*stack_head_a) == 0)
	{
		push_b(stack_head_a, stack_head_b);
		stack_a_len--;
	}
	if (stack_a_len > 3 && is_stack_sorted(*stack_head_a) == 0)
	{
		push_b(stack_head_a, stack_head_b);
		stack_a_len--;
	}
	while (stack_a_len > 3 && is_stack_sorted(*stack_head_a) == 0)
	{
		

	}
	sort_three(stack_head_a);
	while (*stack_head_b != NULL)
	{
	

	}
	set_index(*stack_head_a);

}
