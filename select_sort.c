/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:55:13 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/16 13:34:36 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	int	sorted;

	sorted = 0;
	while (stack->next)
	{
		if ((stack->nb) > (stack->next->nb))
			sorted = 1;
		stack = stack->next;
	}
	return (sorted);
}

static int	count_list(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

void	select_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	nodes;

	nodes = count_list(*stack_a);
	if (is_sorted(*stack_a) == 0)
		return ;
	else if (nodes == 2)
		swap_a(*stack_a);
	else if (nodes == 3)
		sort_three_nodes(stack_a);
	else if (nodes == 4)
		sort_four_nodes(stack_a, stack_b);
	else if (nodes == 5)
		sort_five_nodes(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b, nodes);
}
