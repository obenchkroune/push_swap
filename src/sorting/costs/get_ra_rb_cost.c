/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ra_rb_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:28:55 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/10 17:43:47 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_ra_rb_cost(t_stack *a, t_stack *b)
{
	int		*rotations;
	int		rb_rotations;
	int		ra_rotations;
	t_stack	*b_copy;
	int		max;

	rotations = malloc(sizeof(int) * 3);
	b_copy = copy_stack(b);
	rotations[2] = INT_MAX;
	rb_rotations = 0;
	while (rb_rotations < b->size && rb_rotations < ROTATIONS_CONST)
	{
		ra_rotations = get_ra_cost(a, b_copy);
		max = ft_max(ra_rotations, rb_rotations);
		if (max < rotations[2])
		{
			rotations[0] = ra_rotations;
			rotations[1] = rb_rotations;
			rotations[2] = max;
		}
		rotate(b_copy);
		rb_rotations++;
	}
	cleanup_stack(b_copy);
	return (rotations);
}
