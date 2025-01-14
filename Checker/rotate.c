/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:11:51 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/17 14:28:01 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*temp;
	
	if(*stack == NULL || stack == NULL)
		return ;
	first = *stack;
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = first;
	*stack = (*stack)->next;
	first->next = NULL;
}

void	double_rotate(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*backup;

	if(*stack == NULL || stack == NULL)
		return ;
	backup = *stack;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	while (backup->next->next != NULL)
		backup = backup->next;
	backup->next = NULL;
	last->next = (*stack);
	(*stack) = last;
}

void	double_reverse(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}