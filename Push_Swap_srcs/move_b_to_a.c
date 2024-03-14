/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barpent <barpent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:00:50 by barpent           #+#    #+#             */
/*   Updated: 2024/03/14 12:00:50 by barpent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

static void prepare_stack_a(t_list **stack_head_a, t_list *cheapest, int stack_a_len)
{
    if (cheapest->index <= (stack_a_len / 2))
    {
        while ((*stack_head_a)->data != cheapest->data)
            rotate_b(stack_head_a);
    }
    else
    {
        while ((*stack_head_a)->data != cheapest->data)
            reverse_rotate_b(stack_head_a);
    }
}

static void prepare_stack_b(t_list **stack_head_b, t_list *cheapest, long stack_b_len)
{
    if (cheapest->target->index <= (stack_b_len / 2))
    {
        while ((*stack_head_b)->data != cheapest->target->data)
            rotate_a(stack_head_b);
    }
    else
    {
        while ((*stack_head_b)->data != cheapest->target->data)
            reverse_rotate_a(stack_head_b);
    }
}

void move_b_to_a(t_list **stack_head_a, t_list **stack_head_b)
{
    int stack_a_len;
    int stack_b_len;
    t_list *cheapest;

    cheapest = find_cheapest_cost(*stack_head_b);
    stack_a_len = list_len(*stack_head_a);
    stack_b_len = list_len(*stack_head_b);

    if (cheapest->index <= (stack_b_len / 2) && cheapest->target->index <= (stack_a_len / 2))
        move_rotate_a_and_b(stack_head_b, stack_head_a, cheapest);
    else if (cheapest->index > (stack_a_len / 2) && cheapest->target->index > (stack_b_len / 2))
        move_reverse_rotate_a_and_b(stack_head_a, stack_head_b, cheapest);
    prepare_stack_a(stack_head_b, cheapest, stack_b_len);
    prepare_stack_b(stack_head_a, cheapest, stack_a_len);
    push_a(stack_head_a, stack_head_b);
}