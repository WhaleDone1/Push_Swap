/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barpent <barpent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:03:28 by bcarpent          #+#    #+#             */
/*   Updated: 2024/03/15 17:19:10 by barpent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../Libft/libft.h"
#include "libft.h"
#include "unistd.h"
#include "stdio.h"
#include "lib_push_swap.h"

static void append_node(t_list **stack_head, int n)
{
	t_list *new_node;
	t_list *current;

	if (!stack_head)
		return;
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return;
	new_node->next = NULL;
	new_node->data = n;
	if (*stack_head == NULL)
		*stack_head = new_node;
	else
	{
		current = *stack_head;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
}

static void init_stack(t_list **stack_head, char **argv)
{
	int i;
	long n;

	i = 0;
	*stack_head = NULL;
	while (argv[i])
	{
		// check_syntax(argv[i]);
		n = ft_atol(argv[i]);
		// if (n > 2147483647 || n < -2147483648)
		// free + error;
		// if (check_dupes(*stack_head, (int)n))
		// free + error;
		append_node(stack_head, (int)n);
		i++;
	}
}

int is_stack_sorted(t_list *stack_head)
{
	if (!stack_head)
		return (-1); // error
	while (stack_head->next != NULL)
	{
		if (stack_head->data > stack_head->next->data)
			return (0); // not sorted
		stack_head = stack_head->next;
	}
	return (1); // sorted
}

/*free_stack(t_list **stack_head)
{

}*/

void print_list(t_list *list)
{
	while (list != NULL)
	{
		printf("%d->", list->data);
		list = list->next;
	}
	printf("NULL");
}

int main(int argc, char **argv)
{
	// int i;
	int is_split;
	t_list *stack_a;
	t_list *stack_b;

	is_split = 0;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		init_stack(&stack_a, argv);
		is_split = 1;
	}
	else
		init_stack(&stack_a, argv + 1);
	if (is_stack_sorted(stack_a) == 0)
	{
		if (list_len(stack_a) == 2)
			swap_a(&stack_a, 1);
		else if (list_len(stack_a) == 3)
			sort_three(&stack_a);
		else
			sort_stack(&stack_a, &stack_b);
	}
	// free_stack(&a);
	// rotate_a(&stack_a);
	print_list(stack_a);
	if (is_split == 1)
		free(argv);
	return (0);
}
