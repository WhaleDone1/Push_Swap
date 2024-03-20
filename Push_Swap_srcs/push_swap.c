/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarpent <bcarpent@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:03:28 by bcarpent          #+#    #+#             */
/*   Updated: 2024/03/20 11:02:08 by bcarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"
#include "../Libft/libft.h"
#include "../Printf/ft_printf.h"

static void	append_node(t_list **stack_head, int n)
{
	t_list	*new_node;
	t_list	*current;

	if (!stack_head)
		return ;
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
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

static int	init_stack(t_list **stack_head, char **argv)
{
	int		i;
	long	n;

	i = 0;
	*stack_head = NULL;
	while (argv[i])
	{
		if (check_syntax(argv[i]) == 0)
		{
			ft_free_list(stack_head);
			return (-1);
		}
		n = ft_atol(argv[i]);
		if (n > 2147483647 || n < -2147483648)
			return (-1);
		append_node(stack_head, (int)n);
		i++;
	}
	if (check_dupes(*stack_head) == 1)
		return (-1);
	return (0);
}

int	is_stack_sorted(t_list *stack_head)
{
	if (!stack_head)
		return (-1);
	while (stack_head->next != NULL)
	{
		if (stack_head->data > stack_head->next->data)
			return (0);
		stack_head = stack_head->next;
	}
	return (1);
}

static void	go_push_swap(t_list *stack_a, t_list *stack_b)
{
	set_index(&stack_a);
	if (is_stack_sorted(stack_a) == 0)
	{
		if (list_len(stack_a) == 2)
			swap_a(&stack_a, 1);
		else if (list_len(stack_a) == 3)
			sort_three(&stack_a);
		else
			sort_stack(&stack_a, &stack_b);
	}
}

int	main(int argc, char **argv)
{
	int		is_split;
	int		error;
	t_list	*stack_a;
	t_list	*stack_b;

	is_split = 0;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		error = init_stack(&stack_a, argv);
		is_split = 1;
	}
	else
		error = init_stack(&stack_a, argv + 1);
	if (error == -1)
		ft_printf("Error\n");
	else
		go_push_swap(stack_a, stack_b);
	ft_free_list(&stack_a);
	if (is_split == 1)
		ft_free_split(argv);
	return (0);
}
