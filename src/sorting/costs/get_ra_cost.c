/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ra_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:21:09 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/10 17:43:59 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_ra_cost(t_stack *a, t_stack *b)
{
	int		rotations;
	t_stack	*a_copy;
	t_stack	*b_copy;

	a_copy = copy_stack(a);
	b_copy = copy_stack(b);
	rotations = 0;
	while (!check_position(a_copy, b_copy))
	{
		rotate(a_copy);
		rotations++;
	}
	cleanup_stack(a_copy);
	cleanup_stack(b_copy);
	return (rotations);
}
