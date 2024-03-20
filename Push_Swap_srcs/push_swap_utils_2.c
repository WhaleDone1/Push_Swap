/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barpent <barpent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 05:29:56 by barpent           #+#    #+#             */
/*   Updated: 2024/03/20 11:31:07 by bcarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int	check_dupes(t_list *stack_head)
{
	t_list	*current;
	t_list	*next;

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

int	check_syntax(char *str)
{
	int	i;

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

void	set_target_a(t_list **stack_a, t_list *stack_b)
{
	t_list	*current_a;
	t_list	*current_b;
	t_list	*target_node_a;
	t_list	*biggest_nb_node;

	current_a = *stack_a;
	biggest_nb_node = find_biggest_nb(stack_b);
	while (current_a != NULL)
	{
		current_b = stack_b;
		target_node_a = NULL;
		while (current_b != NULL)
		{
			if (current_b->data < current_a->data)
				if (target_node_a == NULL
					|| current_b->data > target_node_a->data)
					target_node_a = current_b;
			current_b = current_b->next;
		}
		if (target_node_a != NULL)
			current_a->target = target_node_a;
		else
			current_a->target = biggest_nb_node;
		current_a = current_a->next;
	}
}

void	set_target_b(t_list **stack_a, t_list *stack_b)
{
	t_list	*current_a;
	t_list	*current_b;
	t_list	*target_node_b;
	t_list	*smallest_nb_node;

	current_a = *stack_a;
	smallest_nb_node = find_smallest_nb(stack_b);
	while (current_a != NULL)
	{
		current_b = stack_b;
		target_node_b = NULL;
		while (current_b != NULL)
		{
			if (current_b->data > current_a->data)
				if (target_node_b == NULL
					|| current_b->data < target_node_b->data)
					target_node_b = current_b;
			current_b = current_b->next;
		}
		if (target_node_b != NULL)
			current_a->target = target_node_b;
		else
			current_a->target = smallest_nb_node;
		current_a = current_a->next;
	}
}

void	sort_cost(t_list *stack_head_a, t_list *stack_head_b)
{
	long	stack_a_len;
	long	stack_b_len;

	stack_a_len = list_len(stack_head_a);
	stack_b_len = list_len(stack_head_b);
	while (stack_head_a)
	{
		stack_head_a->cost = stack_head_a->index;
		if (stack_head_a->index > (stack_a_len / 2))
			stack_head_a->cost = stack_a_len - (stack_head_a->index);
		if (stack_head_a->target->index <= (stack_b_len / 2))
			stack_head_a->cost += stack_head_a->target->index;
		else
			stack_head_a->cost += stack_b_len - (stack_head_a->target->index);
		stack_head_a = stack_head_a->next;
	}
}
