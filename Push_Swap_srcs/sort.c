/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barpent <barpent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 09:25:06 by bcarpent          #+#    #+#             */
/*   Updated: 2024/03/19 09:30:25 by barpent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"
#include "../Printf/ft_printf.h"

int check_dupes(t_list *stack_head)
{
	t_list *current;
	t_list *next;

	if (stack_head == NULL)
		return (0);
	current = stack_head;
	while (current != NULL)
	{
		next = current->next;
		while (next != NULL)
		{
			if (current->data == next->data)
				return (1);
			next = next->next;
		}
		current = current->next;
	}
	return (0);
}

int check_syntax(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

static void put_min_on_top(t_list **stack_head_a)
{
	t_list *min;

	min = find_smallest_nb(*stack_head_a);
	if (min->index <= list_len(*stack_head_a) / 2)
		while ((*stack_head_a)->data != min->data)
			rotate_a(stack_head_a, 1);
	else
		while ((*stack_head_a)->data != min->data)
			reverse_rotate_a(stack_head_a, 1);
}

void sort_three(t_list **stack_head_a)
{
	t_list *biggest_nb;

	biggest_nb = find_biggest_nb(*stack_head_a);
	if (biggest_nb == *stack_head_a)
		rotate_a(stack_head_a, 1);
	else if ((*stack_head_a)->next == biggest_nb)
		reverse_rotate_a(stack_head_a, 1);
	if ((*stack_head_a)->data > (*stack_head_a)->next->data)
		swap_a(stack_head_a, 1);
}

void sort_stack(t_list **stack_head_a, t_list **stack_head_b)
{
	int stack_a_len;

	stack_a_len = (list_len(*stack_head_a) - 1);
	push_b(stack_head_a, stack_head_b);
	if (--stack_a_len > 3 && is_stack_sorted(*stack_head_a) == 0)
		push_b(stack_head_a, stack_head_b);
	while (stack_a_len > 3 && is_stack_sorted(*stack_head_a) == 0)
	{
		prepare_move_a(*stack_head_a, *stack_head_b);
		move_a_to_b(stack_head_a, stack_head_b);
	}
	if (is_stack_sorted(*stack_head_a) == 0)
		sort_three(stack_head_a);
	while (*stack_head_b != NULL)
	{
		prepare_move_b(*stack_head_a, *stack_head_b);
		move_b_to_a(stack_head_a, stack_head_b);
	}
	set_index(*stack_head_a);
	if (is_stack_sorted(*stack_head_a) == 0)
		put_min_on_top(stack_head_a);
}
