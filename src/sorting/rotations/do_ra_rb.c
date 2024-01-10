/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ra_rb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:16:59 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/10 12:46:51 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_ra_rb(t_stack *a, t_stack *b, int *rotations)
{
	int	ra_moves;
	int	rb_moves;

	ra_moves = rotations[0];
	rb_moves = rotations[1];
	while (ra_moves > 0 && rb_moves > 0)
	{
		rr(a, b);
		ra_moves--;
		rb_moves--;
	}
	while (ra_moves > 0)
	{
		ra(a);
		ra_moves--;
	}
	while (rb_moves > 0)
	{
		rb(b);
		rb_moves--;
	}
}
