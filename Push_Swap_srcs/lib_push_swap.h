/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_push_swap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barpent <barpent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 09:12:39 by bcarpent          #+#    #+#             */
/*   Updated: 2024/03/19 04:56:39 by barpent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PUSH_SWAP_H
#define LIB_PUSH_SWAP_H

#include <stdlib.h>

typedef struct s_list
{
        int data;
        int index;
        int cost;
        struct s_list *target;
        struct s_list *next;
} t_list;

/*
        Sort instructions
                                */

void swap_a(t_list **stack_head_a, int sa);
void swap_b(t_list **stack_head_b, int sb);
void swap_a_and_b(t_list **stack_head_a, t_list **stack_head_b);
void push_a(t_list **stack_head_a, t_list **stack_head_b);
void push_b(t_list **stack_head_a, t_list **stack_head_b);
void rotate_a(t_list **stack_head_a, int ra);
void rotate_b(t_list **stack_head_b, int rb);
void rotate_a_and_b(t_list **stack_head_a, t_list **stack_head_b);
void reverse_rotate_a(t_list **stack_head_a, int rra);
void reverse_rotate_b(t_list **stack_head_b, int rrb);
void reverse_rotate_a_and_b(t_list **stack_head_a, t_list **stack_head_b);

/*
        Utilities
                        */

int list_len(t_list *stack_head);
int is_stack_sorted(t_list *stack_head);
int check_dupes(t_list *stack_head);
int check_syntax(char *str);
t_list *find_biggest_nb(t_list *stack_head);
t_list *find_smallest_nb(t_list *stack_head);
t_list *find_cheapest_cost(t_list *stack_head);
void set_index(t_list *stack_head);
void move_a_to_b(t_list **stack_head_a, t_list **stack_head_b);
void move_b_to_a(t_list **stack_head_a, t_list **stack_head_b);
void move_rotate_a_and_b(t_list **stack_head_a, t_list **stack_head_b, t_list *cheapest);
void move_reverse_rotate_a_and_b(t_list **stack_head_a, t_list **stack_head_b, t_list *cheapest);
void prepare_move_a(t_list *stack_head_a, t_list *stack_head_b);
void prepare_move_b(t_list *stack_head_a, t_list *stack_head_b);
void sort_three(t_list **stack_head_a);
void sort_stack(t_list **stack_head_a, t_list **stack_head_b);
void ft_free_list(t_list **list);
void ft_free_split(char **str);

#endif
