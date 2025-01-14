/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:28:10 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/13 16:34:23 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	t_stack	*current;
	int		temp;

	if (stack == NULL || stack->next == NULL)
		return ;
	current = stack;
	current = current->next;
	temp = stack->nb;
	stack->nb = current->nb;
	stack = stack->next;
	stack->nb = temp;
}

void	swap_a(t_stack *stack)
{
	swap(stack);
	write(1, "sa\n", 3);
}

void	swap_b(t_stack *stack)
{
	swap(stack);
	write(1, "sb\n", 3);
}

void	double_swap(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
