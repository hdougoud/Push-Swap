/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:37:56 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/13 16:30:25 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_error(int n)
{
	if (n == 1)
		ft_putendl_fd("Malloc Error", 2);
	if (n == 2)
		ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

void	check_duplicate(t_stack *stack)
{
	t_stack	*backup;
	t_stack	*checker;

	checker = stack;
	backup = stack;
	while (stack->next != NULL)
	{
		if (stack == checker)
			checker = checker->next;
		if (stack->nb == checker->nb)
		{
			free_stack(backup);
			show_error(2);
		}
		if (checker->next == NULL)
		{
			checker = backup;
			stack = stack->next;
		}
		checker = checker->next;
	}
}

static int	check_limits(int argc, char *argv[])
{
	int		i;
	int		x;
	int		y;
	char	buffer[13];

	i = 0;
	y = 0;
	while (++y < argc)
	{
		x = 0;
		while (argv[y][x])
		{
			buffer[i++] = argv[y][x++];
			if (i > 12)
				return (1);
			if (argv[y][x] == ' ' || argv[y][x] == '\0')
			{
				buffer[i] = '\0';
				if (ft_atol(buffer) > INT_MAX || ft_atol(buffer) < INT_MIN)
					return (1);
				i = 0;
			}
		}
	}
	return (0);
}

static int	check_noascii(int argc, char **argv)
{
	int		i;
	int		j;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == ' ')
				j++;
			if (argv[i][j] == '-' || argv[i][j] == '+')
				j++;
			if (ft_isdigit(argv[i][j]) == 0)
				return (1);
			j++;
		}
	}
	return (0);
}

void	check_errors(int argc, char **argv)
{
	int	error;

	if (argc == 1)
		exit(EXIT_SUCCESS);
	error = check_noascii(argc, argv);
	if (error == 1)
	{
		ft_putendl_fd("Error", 2);
		exit(EXIT_FAILURE);
	}
	error = check_limits(argc, argv);
	if (error == 1)
	{
		ft_putendl_fd("Error", 2);
		exit(EXIT_FAILURE);
	}
}
