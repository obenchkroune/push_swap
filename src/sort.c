/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:18:46 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/10 14:59:51 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *a)
{
	int	min;
	int	max;
	int	*arr;

	if (a->size != 3)
		return ;
	arr = a->arr;
	min = get_min(a);
	max = get_max(a);
	if (arr[0] == max && arr[1] == min)
		ra(a);
	else if (arr[0] == max && arr[2] == min)
	{
		sa(a);
		rra(a);
	}
	else if (arr[1] == max && arr[0] == min)
	{
		rra(a);
		sa(a);
	}
	else if (arr[1] == max && arr[2] == min)
		rra(a);
	else if (arr[2] == max && arr[1] == min)
		sa(a);
}

void	move_min_to_top(t_stack *a)
{
	int	i;
	int	min;
	int	mid;

	i = 0;
	mid = a->size / 2;
	min = get_min(a);
	while (a->arr[i] != min)
		i++;
	while (a->arr[0] != min)
	{
		if (i < mid)
			ra(a);
		else
			rra(a);
	}
}

void	sort_big(t_stack *a, t_stack *b)
{
	push_median_b(a, b);
	if (!is_sorted(a))
		sort_3(a);
	while (b->size > 0)
		rotate_push_a(a, b);
}

void	sort_tiny(t_stack *a, t_stack *b)
{
	while (a->size > 3)
		pb(a, b);
	if (!is_sorted(a))
		sort_3(a);
	while (b->size > 0)
		rotate_push_a(a, b);
	
}

void	sort_stack(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		ra(a);
	else if (a->size == 3)
		sort_3(a);
	else if (a->size <= 10)
		sort_tiny(a, b);
	else
		sort_big(a, b);
	move_min_to_top(a);
}
