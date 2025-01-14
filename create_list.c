/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:18:29 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/13 17:17:04 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*fill_array(int argc, char **argv, int *tab)
{
	char	buffer[13];
	int		tab_pos;
	int		x;
	int		y;
	int		i;

	y = 0;
	tab_pos = 0;
	while (++y < argc)
	{
		x = 0;
		while (argv[y][x])
		{
			i = 0;
			while (argv[y][x] && argv[y][x] != ' ')
				buffer[i++] = argv[y][x++];
			buffer[i] = '\0';
			tab[tab_pos] = ft_atoi(buffer);
			tab_pos++;
			if (argv[y][x] != '\0')
				x++;
		}
	}
	return (tab);
}

static int	*create_array(int argc, char **argv, int *size)
{
	int	*tab;
	int	i;
	int	j;

	j = 0;
	tab = NULL;
	(*size) = 0;
	while (++j < argc)
	{
		i = 0;
		while (argv[j][i])
		{
			if (argv[j][i] == ' ')
				(*size)++;
			i++;
		}
		(*size)++;
	}
	tab = malloc(sizeof(int) * (*size));
	if (!tab)
		show_error(1);
	return (fill_array(argc, argv, tab));
}

static t_stack	*add_stack_a(int n, int *array)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
	{
		if (array)
			safe_free((void **) &array);
		return (NULL);
	}
	new->nb = n;
	new->next = NULL;
	return (new);
}

t_stack	*create_list(int argc, char **argv, t_stack *stack_a)
{
	t_stack	*current;
	int		*array;
	int		size;
	int		i;

	i = 0;
	array = create_array(argc, argv, &size);
	stack_a = add_stack_a(array[i], array);
	if (!stack_a)
		show_error(1);
	current = stack_a;
	while (++i < size)
	{
		current->next = add_stack_a(array[i], array);
		if (!current->next)
		{
			free_stack(stack_a);
			show_error(1);
		}
		current = current->next;
	}
	safe_free((void **) &array);
	return (stack_a);
}
