/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarpent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 09:15:55 by bcarpent          #+#    #+#             */
/*   Updated: 2024/03/12 16:41:57 by bcarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

/*void	print_list(t_list *list)
{
	if (list != NULL)
	{
		ft_printf("%d->", list->data);
		print_list(list->next);
	}
	else
		ft_printf("NULL");
}*/

/*t_list	*change_list_head(t_list *stackhead, int newdata)
{
	t_list	*newnode = malloc(sizeof(t_list));
	newnode->data = newdata;
	if (stackhead != NULL)
		newnode->next = stackhead;
	else
		newnode->next = NULL;
	return (newnode);
}*/

int	list_len(t_list **stack_head)
{
	int	i;

	i = 0;
	while (*stack_head != NULL)
	{
		i++;
		*stack_head = (*stack_head)->next;
	}
	return (i);
}

t_list	*find_biggest_nb(t_list *stack_head)
{
	t_list *biggest_nb;

	biggest_nb = stack_head;
	while (stack_head->next != NULL)
	{
		stack_head = stack_head->next;
		if (biggest_nb->data < stack_head->data)
			biggest_nb = stack_head;
	}
	return (biggest_nb);
}

void	set_index(t_list *stack_head)
{
	int	i;

	i = 0;
	if (!stack_head)
		return ;
	while (stack_head != NULL)
	{
		stack_head->index = i;
		i++;
	}
}
