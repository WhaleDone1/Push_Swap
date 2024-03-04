/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarpent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 09:15:55 by bcarpent          #+#    #+#             */
/*   Updated: 2024/03/04 10:03:04 by bcarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef	struct t_list
{
	int	data;
	t_list	*next;
}t_list;

void	print_list(t_list *stackhead)
{
	if (stackHead != NULL)
	{
		ft_printf("%d->", stackhead->data);
		print_list(stackHead->next);
	}
	else
		ft_printf("NULL");
}

t_list	*change_list_head(t_list *stackhead, int newdata)
{
	t_list	*newnode = malloc(sizeof(t_list));
	newnode->data = newdata;
	if (stackhead != NULL)
		newnode->next = stackhead;
	else
		newnode->next = NULL;
	return (newnode);
}
