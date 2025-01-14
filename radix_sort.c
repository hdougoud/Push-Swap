/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:55:17 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/16 13:35:10 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_binary(long nb)
{
	int	bits;

	bits = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 2;
		bits++;
	}
	return (bits);
}

static int	get_max_bits(t_stack *stack)
{
	long	max;

	max = stack->nb;
	while (stack)
	{
		if (stack->nb > max)
			max = stack->nb;
		stack = stack->next;
	}
	return (get_binary(max));
}

static long	get_next_min(t_stack *stack, long min, int *pos)
{
	int		i;
	long	lowest_value;

	i = 0;
	*pos = 0;
	lowest_value = INT_MAX + 1L;
	while (stack)
	{
		if (stack->nb > min && stack->nb < lowest_value)
		{
			lowest_value = stack->nb;
			*pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (lowest_value);
}

static void	convert_list(t_stack *stack, int nodes)
{
	int		i;
	long	min;
	int		pos;
	int		*tab;

	i = 0;
	min = INT_MIN - 1;
	tab = malloc(sizeof(int) * nodes);
	if (!tab)
		show_error(1);
	while (i < nodes)
	{
		min = get_next_min(stack, min, &pos);
		tab[pos] = i;
		i++;
	}
	i = 0;
	while (stack)
	{
		stack->nb = tab[i];
		stack = stack->next;
		i++;
	}
	free(tab);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b, int nodes)
{
	int	bits;
	int	bnodes;
	int	max_bits;

	bnodes = nodes;
	convert_list(*stack_a, nodes);
	max_bits = get_max_bits(*stack_a);
	bits = -1;
	while (++bits < max_bits)
	{
		while (bnodes > 0)
		{
			if ((((*stack_a)->nb >> bits) & 1) == 0)
				push_b(stack_a, stack_b);
			else
				rotate_a(stack_a);
			bnodes--;
		}
		bnodes = nodes;
		while (*stack_b)
			push_a(stack_b, stack_a);
	}
	if (is_sorted(*stack_a) == 0)
		return ;
}
