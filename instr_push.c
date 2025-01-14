/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:54:59 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/13 16:33:09 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **stack_src, t_stack **stack_dest)
{
	t_stack	*temp;

	if ((*stack_src) == NULL)
		return ;
	temp = (*stack_src);
	*stack_src = (*stack_src)->next;
	temp->next = *stack_dest;
	(*stack_dest) = temp;
}

void	push_a(t_stack **stack_src, t_stack **stack_dest)
{
	push(stack_src, stack_dest);
	write(1, "pa\n", 3);
}

void	push_b(t_stack **stack_src, t_stack **stack_dest)
{
	push(stack_src, stack_dest);
	write(1, "pb\n", 3);
}
