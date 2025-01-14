/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_rev_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:32:18 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/17 14:28:30 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
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

void	reverse_rotate_a(t_stack **stack)
{
	reverse_rotate(stack);
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack **stack)
{
	reverse_rotate(stack);
	write(1, "rrb\n", 4);
}

void	double_reverse(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
