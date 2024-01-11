/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ra_rrb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:46:53 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/10 17:43:41 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_ra_rrb_cost(t_stack *a, t_stack *b)
{
	int		ra_rotations;
	int		rrb_rotations;
	t_stack	*b_copy;
	int		*rotations;

	rotations = malloc(sizeof(int) * 3);
	b_copy = copy_stack(b);
	rotations[2] = INT_MAX;
	rrb_rotations = 0;
	while (rrb_rotations < b->size && rrb_rotations < ROTATIONS_CONST)
	{
		ra_rotations = get_ra_cost(a, b_copy);
		if (ra_rotations + rrb_rotations < rotations[2])
		{
			rotations[0] = ra_rotations;
			rotations[1] = rrb_rotations;
			rotations[2] = ra_rotations + rrb_rotations;
		}
		reverse_rotate(b_copy);
		rrb_rotations++;
	}
	cleanup_stack(b_copy);
	return (rotations);
}
