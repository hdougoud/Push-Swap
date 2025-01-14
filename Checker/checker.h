/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:40:55 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/17 14:14:17 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
#define CHECKER_H

# include "../libft/libft.h"

typedef struct s_stack
{
	long			nb;
	struct s_stack	*next;
}					t_stack;

void	show_error(int n);
void	swap(t_stack *stack);
void	rotate(t_stack **stack);
void	free_stack(t_stack *stack);
void	reverse_rotate(t_stack **stack);
void	check_duplicate(t_stack *stack);
void	check_errors(int argc, char **argv);
void	push(t_stack **stack_src, t_stack **stack_dest);
void	double_swap(t_stack *stack_a, t_stack *stack_b);
void	double_rotate(t_stack **stack_a, t_stack **stack_b);
void	double_reverse(t_stack **stack_a, t_stack **stack_b);
t_stack	*create_list(int argc, char **argv, t_stack *stack_a);


#endif