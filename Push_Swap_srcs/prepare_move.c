/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barpent <barpent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:41:10 by bcarpent          #+#    #+#             */
/*   Updated: 2024/03/14 12:50:43 by barpent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

static void set_target_a(t_list *stack_head_a, t_list *stack_head_b)
{
	t_list *target;
	t_list *tmp_match;
	long match;

	while (stack_head_a != NULL)
	{
		match = -9223372036854775807;
		tmp_match = stack_head_b;
		while (tmp_match)
		{
			if (tmp_match->data > stack_head_a->data && tmp_match->data > match)
			{
				match = tmp_match->data;
				target = tmp_match;
			}
			tmp_match = tmp_match->next;
		}
		if (match == -9223372036854775807)
			stack_head_a->target = find_biggest_nb(stack_head_b);
		else
			stack_head_a->target = target;
		stack_head_a = stack_head_a->next;
	}
}

static void set_target_b(t_list *stack_head_a, t_list *stack_head_b)
{
	t_list *target;
	t_list *tmp_match;
	long match;

	while (stack_head_a != NULL)
	{
		match = 9223372036854775807;
		tmp_match = stack_head_a;
		while (tmp_match)
		{
			if (tmp_match->data > stack_head_b->data && tmp_match->data < match)
			{
				match = tmp_match->data;
				target = tmp_match;
			}
			tmp_match = tmp_match->next;
		}
		if (match == 9223372036854775807)
			stack_head_b->target = find_smallest_nb(stack_head_a);
		else
			stack_head_a->target = target;
		stack_head_a = stack_head_a->next;
	}
}

static void sort_cost(t_list *stack_head_a, t_list *stack_head_b)
{
	int stack_len_a;
	int stack_len_b;

	stack_len_a = list_len(stack_head_a);
	stack_len_b = list_len(stack_head_b);

	while (stack_head_a != NULL)
	{
		stack_head_a->cost = stack_head_a->index;
		if (stack_head_a->index > (stack_len_a / 2))
			stack_head_a->cost = stack_len_a - (stack_head_a->index);
		if (stack_head_a->target->index <= (stack_len_b / 2))
			stack_head_a->cost += stack_head_a->target->index;
		else
			stack_head_a->cost += stack_len_b - (stack_head_a->target->index);
		stack_head_a = stack_head_a->next;
	}
}

void prepare_move_a(t_list *stack_head_a, t_list *stack_head_b)
{
	set_index(stack_head_a);
	set_index(stack_head_b);
	set_target_a(stack_head_a, stack_head_b);
	sort_cost(stack_head_a, stack_head_b);
}

void prepare_move_b(t_list *stack_head_a, t_list *stack_head_b)
{
	set_index(stack_head_a);
	set_index(stack_head_b);
	set_target_b(stack_head_a, stack_head_b);
}