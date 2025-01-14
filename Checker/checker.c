/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:40:35 by hdougoud          #+#    #+#             */
/*   Updated: 2024/12/17 14:35:33 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"


static int	check_result(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->nb > stack->next->nb)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static void	apply_args(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (ft_strncmp("sa", line, 2) == 0)
		swap(*stack_a);
	else if (ft_strncmp("sb", line, 2) == 0)
		swap(*stack_b);
	else if (ft_strncmp("ss", line, 2) == 0)
		double_swap(*stack_a, *stack_b);
	else if (ft_strncmp("pa", line, 2) == 0)
		push(stack_b, stack_a);
	else if (ft_strncmp("pb", line, 2) == 0)
		push(stack_a, stack_b);
	else if (ft_strncmp("ra", line, 2) == 0)
		rotate(stack_a);
	else if (ft_strncmp("rb", line, 2) == 0)
		rotate(stack_b);
	else if (ft_strncmp("rr\n", line, 3) == 0)
		double_rotate(stack_a, stack_b);
	else if (ft_strncmp("rra", line, 3) == 0)
		reverse_rotate(stack_a);
	else if (ft_strncmp("rrb", line, 3) == 0)
		reverse_rotate(stack_b);
	else if (ft_strncmp("rrr", line, 3) == 0)
		double_reverse(stack_a, stack_b);
	else
		show_error(2);
}

void	free_stack(t_stack *stack)
{
	t_stack	*backup;

	backup = stack;
	while (stack)
	{
		backup = backup->next;
		free (stack);
		stack = backup;
	}
}

int main(int argc, char **argv)
{
	char *line;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	check_errors(argc, argv);
	stack_a = create_list(argc, argv, stack_a);
	check_duplicate(stack_a);
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
			break ;
		apply_args(&stack_a, &stack_b, line);
		free(line);
	}
	if (check_result(stack_a) == 1)
		ft_putendl_fd("KO", 1);
	else
		ft_putendl_fd("OK", 1);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
