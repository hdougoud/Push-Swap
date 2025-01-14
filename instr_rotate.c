/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:47:49 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/17 14:28:43 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
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

void	rotate_a(t_stack **stack)
{
	rotate(stack);
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack **stack)
{
	rotate(stack);
	write(1, "rb\n", 3);
}

void	double_rotate(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
