/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rra_cost.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:08:02 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/10 08:57:48 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_rra_cost(t_stack *stack_a, t_stack *stack_b)
{
	int		rotations;
	t_stack	*a_copy;
	t_stack	*b_copy;

	a_copy = copy_stack(stack_a);
	b_copy = copy_stack(stack_b);
	rotations = 0;
	while (!check_position(a_copy, b_copy))
	{
		reverse_rotate(a_copy);
		rotations++;
	}
	cleanup_stack(a_copy);
	cleanup_stack(b_copy);
	return (rotations);
}
