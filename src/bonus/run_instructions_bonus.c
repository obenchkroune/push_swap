/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_instructions_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:52:35 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/11 10:08:00 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	execute_instruction(\
		char *instruction, t_stack *a, t_stack *b, char **numbers)
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
