/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:42:14 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/09 17:48:56 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_position(t_stack *a, t_stack *b)
{
	int	min;
	int	max;
	int	head;
	int	tail;

	min = get_min(a);
	max = get_max(a);
	head = get_head(a);
	tail = get_tail(a);
	if ((b->arr[0] > max && head == min) || \
		(b->arr[0] < min && head == min) \
		|| b->arr[0] < head && b->arr[0] > tail)
	{
		return (1);
	}
	return (0);
}
