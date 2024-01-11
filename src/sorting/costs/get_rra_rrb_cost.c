/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rra_rrb_cost.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:47:25 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/10 17:43:36 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_rra_rrb_cost(t_stack *a, t_stack *b)
{
	int		*rotations;
	int		rrb_rotations;
	int		rra_rotations;
	t_stack	*b_copy;
	int		max;

	rotations = malloc(sizeof(int) * 3);
	b_copy = copy_stack(b);
	rotations[2] = INT_MAX;
	rrb_rotations = 0;
	while (rrb_rotations < b->size && rrb_rotations < ROTATIONS_CONST)
	{
		rra_rotations = get_rra_cost(a, b_copy);
		max = ft_max(rra_rotations, rrb_rotations);
		if (max < rotations[2])
		{
			rotations[0] = rra_rotations;
			rotations[1] = rrb_rotations;
			rotations[2] = max;
		}
		reverse_rotate(b_copy);
		rrb_rotations++;
	}
	cleanup_stack(b_copy);
	return (rotations);
}
