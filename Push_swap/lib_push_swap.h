/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_push_swap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarpent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 09:12:39 by bcarpent          #+#    #+#             */
/*   Updated: 2024/03/12 16:28:15 by bcarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PUSH_SWAP_H
# define LIB_PUSH_SWAP_H

#include <stdlib.h>

typedef struct s_list
{
        int             data;
        int             index;
        int             cost;
        int             cheapest;
        struct s_list   *target;
        struct s_list   *next;
} t_list;

void	swap_a(t_list **stack_head_a);
void	swap_b(t_list **stack_head_b);
void	swap_a_and_b(t_list **stack_head_a, t_list **stack_head_b);
void	push_a(t_list **stack_head_a, t_list **stack_head_b);
void	push_b(t_list **stack_head_a, t_list **stack_head_b);
void	rotate_a(t_list **stack_head_a);
void	rotate_b(t_list **stack_head_b);
void	rotate_a_and_b(t_list **stack_head_a, t_list **stack_head_b);
void	reverse_rotate_a(t_list **stack_head_a);
void	reverse_rotate_b(t_list **stack_head_b);
void	reverse_rotate_a_and_b(t_list **stack_head_a, t_list **stack_head_b);

#endif
