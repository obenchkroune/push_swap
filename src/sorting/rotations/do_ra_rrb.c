/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ra_rrb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:18:04 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/10 12:18:16 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_ra_rrb(t_stack *a, t_stack *b, int *rotations)
{
	while (rotations[0]--)
		ra(a);
	while (rotations[1]--)
		rrb(b);
}
