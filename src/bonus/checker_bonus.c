/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:56:19 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/11 09:33:18 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void \
execute_instruction(char *instruction, t_stack *a, t_stack *b, char **numbers)
{
	if (ft_strncmp(instruction, "ra\n", 3) == 0)
		rotate(a);
	else if (ft_strncmp(instruction, "rb\n", 3) == 0)
		rotate(b);
	else if (ft_strncmp(instruction, "rr\n", 3) == 0)
	{
		rotate(a);
		rotate(b);
	}
	else if (ft_strncmp(instruction, "rra\n", 4) == 0)
		reverse_rotate(a);
	else if (ft_strncmp(instruction, "rrb\n", 4) == 0)
		reverse_rotate(b);
	else if (ft_strncmp(instruction, "rrr\n", 4) == 0)
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
	else if (ft_strncmp(instruction, "sa\n", 3) == 0)
		swap(a);
	else if (ft_strncmp(instruction, "sb\n", 3) == 0)
		swap(b);
	else if (ft_strncmp(instruction, "ss\n", 3) == 0)
	{
		swap(a);
		swap(b);
	}
	else if (ft_strncmp(instruction, "pa\n", 3) == 0)
		push(a, b);
	else if (ft_strncmp(instruction, "pb\n", 3) == 0)
		push(b, a);
	else
	{
		cleanup(a, b, numbers);
		ft_putendl_fd("Error", 2);
		exit(1);
	}
}

void	run_instructions(t_stack *a, t_stack *b, char **numbers)
{
	char	*instruction;

	while (1)
	{
		instruction = get_next_line(0);
		if (!instruction)
			break ;
		execute_instruction(instruction, a, b, numbers);
		free(instruction);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**numbers;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	parse_numbers(&numbers, argc, argv);
	check_errors(numbers);
	init_stacks(&a, &b, numbers);
	run_instructions(a, b, numbers);
	if (is_sorted(a) && b->size == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 2);
	cleanup(a, b, numbers);
	return (0);
}
