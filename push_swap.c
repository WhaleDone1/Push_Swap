/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barpent <barpent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:03:28 by bcarpent          #+#    #+#             */
/*   Updated: 2024/03/08 16:54:53 by barpent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct t_list
{
	int data;
	t_list *next;
} t_list;

/*void	print_list(t_list *stackhead)
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
}*/

void swap_a(t_list **stack_head_a)
{
	t_list *current;
	t_list *next;
	int tmp_data;

	if (!stack_head_a || !*stack_head_a || !(*stack_head_a)->next)
		return;
	current = *stack_head_a;
	next = current->next;
	tmp_data = current->data;
	current->data = next->data;
	next->data = tmp_data;
}

void swap_b(t_list **stack_head_b)
{
	t_list *current;
	t_list *next;
	int tmp_data;

	if (!stack_head_b || !*stack_head_b || !(*stack_head_b)->next)
		return;
	current = *stack_head_b;
	next = current->next;
	tmp_data = current->data;
	current->data = next->data;
	next->data = tmp_data;
}

void swap_a_and_b(t_list **stack_head_a, t_list **stack_head_b)
{
	if (!stack_head_a || !*stack_head_a || !stack_head_b || !*stack_head_b)
		return;

	swap_a(stack_head_a);
	swap_b(stack_head_b);
}

void push_a(t_list **stack_head_a, t_list **stack_head_b)
{
	if (!stack_head_a || !stack_head_b || !*stack_head_b)
		return;

	t_list *new_top;
	new_top = *stack_head_b;
	*stack_head_b = (*stack_head_b)->next;
	new_top->next = *stack_head_a;
	*stack_head_a = new_top;
}

void push_b(t_list **stack_head_a, t_list **stack_head_b)
{
	if (!stack_head_a || !stack_head_b || !*stack_head_a)
		return;

	t_list *new_top;
	new_top = *stack_head_a;
	*stack_head_a = (*stack_head_a)->next;
	new_top->next = *stack_head_b;
	*stack_head_b = new_top;
}

void rotate_a(t_list **stack_head_a)
{
	t_list *tmp_ptr;

	if (!stack_head_a || !*stack_head_a || !(*stack_head_a)->next)
		return;
	tmp_ptr = *stack_head_a;
	while (tmp_ptr->next != NULL)
		tmp_ptr = tmp_ptr->next;
	tmp_ptr->next = *stack_head_a;
	*stack_head_a = (*stack_head_a)->next;
	tmp_ptr = tmp_ptr->next;
	tmp_ptr->next = NULL;
}

void rotate_b(t_list **stack_head_b)
{
	t_list *tmp_ptr;

	if (!stack_head_b || !*stack_head_b || !(*stack_head_b)->next)
		return;
	tmp_ptr = *stack_head_b;
	while (tmp_ptr->next != NULL)
		tmp_ptr = tmp_ptr->next;
	tmp_ptr->next = *stack_head_b;
	*stack_head_b = (*stack_head_b)->next;
	tmp_ptr = tmp_ptr->next;
	tmp_ptr->next = NULL;
}

void rotate_a_and_b(t_list **stack_head_a, t_list **stack_head_b)
{
	if (!stack_head_a || !*stack_head_a || !stack_head_b || !*stack_head_b)
		return;
	rotate_a(stack_head_a);
	rotate_b(stack_head_b);
}

void reverse_rotate_a(t_list **stack_head_a)
{

	t_list *last;
	t_list *before_last = NULL;

	if (!stack_head_a || !*stack_head_a || !(*stack_head_a)->next)
		return;
	last = *stack_head_a;
	while (last->next != NULL)
	{
		before_last = last;
		last = last->next;
	}
	last->next = *stack_head_a;
	*stack_head_a = last;
	before_last->next = NULL;
}

void reverse_rotate_b(t_list **stack_head_b)
{

	t_list *last;
	t_list *before_last;

	if (!stack_head_b || !*stack_head_b || !(*stack_head_b)->next)
		return;
	last = *stack_head_b;
	while (last->next != NULL)
	{
		before_last = last;
		last = last->next;
	}
	last->next = *stack_head_b;
	*stack_head_b = last;
	before_last->next = NULL;
}