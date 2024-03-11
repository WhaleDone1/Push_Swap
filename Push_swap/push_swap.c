/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barpent <barpent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:03:28 by bcarpent          #+#    #+#             */
/*   Updated: 2024/03/11 11:00:15 by bcarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "lib_push_swap.h"


static void	init_stack(t_list **stack_head, char **argv)
 {
	int	i;
 	long	n;

	i = 0;
	while (argv[i])
	{
 		//check_syntax(argv[i]);
		n = ft_atol(argv[i]);
		if (n > 2147483647 || n < -2147483648)
			//free + error;
		if (/*check_dupes(*stack_head, (int)n)*/)
			//free + error;
		append_node(stack_head, (int)n);
		i++;
	}
	
 }

static void	append_node(t_list **stack_head, int n)
{
	t_list *new_node;

	if (!stack_head)
		return ;
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->data = n;
	if (!stack_head)
		*stack_head = node;
	else
	{
		while (stack_head->next != NULL)
			*stack_head = (*stack_head)->next;
		(*stack_head)->next = node;
	}
}

/*free_stack(t_list **stack_head)
{

}*/

int	stack_sorted(t_list *stack_head)
{
	if (!stack_head)
		return (-1); //error
	while (stack_head->next != NULL)
	{
		if (stack_head->data > stack_head->next->data)
			return (0); //not sorted
		stack_head = steack_head->next;
	}
	return (1); //sorted
}

int	main(int argc, char **argv)
{
	int	i;
	t_list *stack_a;

	if (argc == 1 || argc == 2 && !argv[1][0])
		return (NULL);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	init_stack(&a, argv[1]);
	if (stack_sorted(stack_a) < 0)
	{
		if (stack_len == 2)
			//sa(&)
		else if (stack_len == 3)
			//sort_three(&)
		else
			//sort_stack(&)
	}
	//free_stack(&a);
	return (0);
}
