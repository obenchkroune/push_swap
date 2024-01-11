/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_instructions_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:52:35 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/11 10:14:07 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	reverse_rotate_both(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}

static void	rotate_both(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
}

static void	swap_both(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}

static void	execute_instruction(\
		char *instruction, t_stack *a, t_stack *b, char **numbers)
{
	if (ft_strncmp(instruction, "ra\n", 3) == 0)
		return (rotate(a));
	else if (ft_strncmp(instruction, "rb\n", 3) == 0)
		return (rotate(b));
	else if (ft_strncmp(instruction, "rr\n", 3) == 0)
		return (rotate_both(a, b));
	else if (ft_strncmp(instruction, "rra\n", 4) == 0)
		return (reverse_rotate(a));
	else if (ft_strncmp(instruction, "rrb\n", 4) == 0)
		return (reverse_rotate(b));
	else if (ft_strncmp(instruction, "rrr\n", 4) == 0)
		return (reverse_rotate_both(a, b));
	else if (ft_strncmp(instruction, "sa\n", 3) == 0)
		return (swap(a));
	else if (ft_strncmp(instruction, "sb\n", 3) == 0)
		return (swap(b));
	else if (ft_strncmp(instruction, "ss\n", 3) == 0)
		return (swap_both(a, b));
	else if (ft_strncmp(instruction, "pa\n", 3) == 0)
		return (push(a, b));
	else if (ft_strncmp(instruction, "pb\n", 3) == 0)
		return (push(b, a));
	cleanup(a, b, numbers);
	ft_putendl_fd("Error", 2);
	exit(1);
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
