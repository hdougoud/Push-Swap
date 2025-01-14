/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:03:51 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/17 14:28:18 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap(t_stack *stack)
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

void	double_swap(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

void	push(t_stack **stack_src, t_stack **stack_dest)
{
	t_stack	*temp;

	if ((*stack_src) == NULL)
		return ;
	temp = (*stack_src);
	*stack_src = (*stack_src)->next;
	temp->next = *stack_dest;
	(*stack_dest) = temp;
}