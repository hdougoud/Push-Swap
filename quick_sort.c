/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:23:22 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/17 11:46:56 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_nodes(t_stack **stack_a)
{
	if ((((*stack_a)->nb > (*stack_a)->next->nb))
		&& ((*stack_a)->next->nb > (*stack_a)->next->next->nb))
		swap_a(*stack_a);
	if ((*stack_a)->nb > (*stack_a)->next->next->nb
		&& (*stack_a)->next->nb < (*stack_a)->next->next->nb)
		rotate_a(stack_a);
	if (((*stack_a)->nb < (*stack_a)->next->nb
			&& (*stack_a)->nb > (*stack_a)->next->next->nb)
		|| ((*stack_a)->next->nb > (*stack_a)->next->next->nb))
		reverse_rotate_a(stack_a);
	if ((*stack_a)->nb > ((*stack_a)->next->nb))
		swap_a(*stack_a);
}

static void	utils_four_nodes(t_stack **stack_a, t_stack **stack_b, int low)
{
	int		i;
	t_stack	*index;

	index = *stack_a;
	i = 0;
	while (index->nb != low)
	{
		index = index->next;
		i++;
	}
	if (i == 1)
		rotate_a(stack_a);
	if (i == 2)
	{
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
	if (i == 3)
		reverse_rotate_a(stack_a);
	push_b(stack_a, stack_b);
}

void	sort_four_nodes(t_stack **stack_a, t_stack **stack_b)
{
	int		low;
	t_stack	*index;

	index = *stack_a;
	low = index->nb;
	while (index)
	{
		if (index->nb < low)
			low = index->nb;
		index = index->next;
	}
	utils_four_nodes(stack_a, stack_b, low);
	sort_three_nodes(stack_a);
	push_a(stack_b, stack_a);
}

static void	utils_five_nodes(t_stack **stack_a, t_stack **stack_b, int low)
{
	int		i;
	t_stack	*index;

	i = 0;
	index = *stack_a;
	while (index->nb != low)
	{
		index = index->next;
		i++;
	}
	if (i == 1)
		rotate_a(stack_a);
	if (i == 2)
	{
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
	if (i == 3)
	{
		reverse_rotate_a(stack_a);
		reverse_rotate_a(stack_a);
	}
	if (i == 4)
		reverse_rotate_a(stack_a);
	push_b(stack_a, stack_b);
}

void	sort_five_nodes(t_stack **stack_a, t_stack **stack_b)
{
	int		low;
	t_stack	*index;

	index = *stack_a;
	low = index->nb;
	while (index)
	{
		if (low > index->nb)
			low = index->nb;
		index = index->next;
	}
	utils_five_nodes(stack_a, stack_b, low);
	sort_four_nodes(stack_a, stack_b);
	push_a(stack_b, stack_a);
}
