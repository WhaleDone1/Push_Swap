/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_push_swap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarpent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 09:12:39 by bcarpent          #+#    #+#             */
/*   Updated: 2024/03/11 09:29:21 by bcarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PUSH_SWAP_H
# define LIB_PUSH_SWAP_H

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

typedef struct t_list
{
	int data;
	t_list *next;
} t_list;

#endif
