/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:05:19 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/16 13:32:27 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	long			nb;
	struct s_stack	*next;
}					t_stack;

int			is_sorted(t_stack *stack);

void		show_error(int n);
void		free_stack(t_stack *stack);
void		check_duplicate(t_stack *stack);
void		check_errors(int argc, char **argv);
void		select_sort(t_stack **stack_a, t_stack **stack_b);

t_stack		*new_node(int n);
t_stack		*create_list(int argc, char **argv, t_stack *stack_a);

/*------------------------------Sort-------------------------------*/

void		sort_two_nodes(t_stack *stack_a);
void		sort_three_nodes(t_stack **stack_a);
void		sort_four_nodes(t_stack **stack_a, t_stack **stack_b);
void		sort_five_nodes(t_stack **stack_a, t_stack **stack_b);
void		radix_sort(t_stack **stack_a, t_stack **stack_b, int nodes);

/*-------------------------Opeartor--------------------------------*/

void		swap_a(t_stack *stack);
void		swap_b(t_stack *stack);
void		double_swap(t_stack *stack_a, t_stack *stack_b);
void		push_a(t_stack **stack_src, t_stack **stack_dest);
void		push_b(t_stack **stack_src, t_stack **stack_dest);
void		rotate_a(t_stack **stack);
void		rotate_b(t_stack **stack);
void		double_rotate(t_stack **stack_a, t_stack **stack_b);
void		reverse_rotate_a(t_stack **stack);
void		reverse_rotate_b(t_stack **stack);
void		double_reverse(t_stack **stack_a, t_stack **stack_b);

#endif