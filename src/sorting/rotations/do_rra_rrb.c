/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rra_rrb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:17:38 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/10 12:48:38 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rra_rrb(t_stack *a, t_stack *b, int *rotations)
{
	int	rra_moves;
	int	rrb_moves;

	rra_moves = rotations[0];
	rrb_moves = rotations[1];
	while (rra_moves > 0 && rrb_moves > 0)
	{
		rrr(a, b);
		rra_moves--;
		rrb_moves--;
	}
	while (rra_moves > 0)
	{
		rra(a);
		rra_moves--;
	}
	while (rrb_moves > 0)
	{
		rrb(b);
		rrb_moves--;
	}
}
