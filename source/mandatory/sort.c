/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 10:53:27 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/07 15:42:59 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	sort_three(t_stack *a)
{
	int	min;
	int	max;

	min = get_min(a);
	max = get_max(a);
	if (a->array[2] == min && a->array[0] == max)
	{
		sa(a);
		rra(a);
	}
	else if (a->array[1] == min && a->array[0] == max)
		ra(a);
	else if (a->array[1] == min && a->array[2] == max)
		sa(a);
	else if (a->array[1] == max && a->array[0] == min)
	{
		rra(a);
		sa(a);
	}
	else if (a->array[2] == min && a->array[1] == max)
		rra(a);
}

void	move_to_b(t_stack *a, t_stack *b)
{
	int	median;

	median = get_median(a);
	while (a->size > 3)
	{
		pb(a, b);
		if (b->size > 1 && b->array[0] > median)
			rb(b);
	}
}

int	get_b_distance(t_stack *a, t_stack *b)
{
	int	distance_a;
	int	distance_b;
	int	a_value;
	int	b_value;

	b_value = get_next_min(b, a->array[0]);
	a_value = get_min_big(a, b_value);
	distance_a = get_optimized_distance(a, a_value);
	distance_b = get_optimized_distance(b, b_value);
	if (distance_a < distance_b)
		return (distance_b);
	return (distance_a);
}

int	get_b2_distance(t_stack *a, t_stack *b)
{
	int	distance_a;
	int	distance_b;
	int	a_value;
	int	b_value;

	b_value = get_next_min_reverse(b, a->array[0]);
	a_value = get_min_big(a, b_value);
	distance_a = get_optimized_distance(a, a_value);
	distance_b = get_optimized_distance(b, b_value);
	if (distance_a < distance_b)
		return (distance_b);
	return (distance_a);
}

static int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

typedef struct s_distance
{
	int	optimized;
	int	real;
}	t_distence;

void	do_rr_rrr(t_stack *a, t_stack *b, int b_val)
{
	int	a_value;
	int	b_value;
	int	min;
	t_distence	a_dist;
	t_distence	b_dist;

	b_value = b_val;
	a_value = get_min_big(a, b_value);
	a_dist.real = get_distance(a, a_value);
	b_dist.real = get_distance(b, b_value);
	a_dist.optimized = get_optimized_distance(a, a_value);
	b_dist.optimized = get_optimized_distance(b, b_value);
	min = ft_min(a_dist.optimized, b_dist.optimized);
	if (a_dist.real < a->size / 2 && b_dist.real < b->size / 2)
		while (min--)
			rr(a, b);
	else if (a_dist.real >= a->size / 2 && b_dist.real >= b->size / 2)
		while (min--)
			rrr(a, b);
	smart_rotate_a(a, b, a_value);
	smart_rotate_b(a, b, b_value);
}

int	get_a_distance(t_stack *a, t_stack *b)
{
	int	distance;
	int	value;

	value = get_min_big(a, b->array[0]);
	return (get_optimized_distance(a, value));
}

void	do_cheapest_move(t_stack *a, t_stack *b)
{
	int	distance_a;
	int	distance_b;
	int	distance_b2;
	int distance_b3;

	distance_a = get_a_distance(a, b);
	distance_b = get_b_distance(a, b);
	distance_b2 = get_b2_distance(a, b);
	distance_b3 = get_optimized_distance(a, get_min_big(a, b->array[1]));
	if (distance_b3 < distance_b2 && distance_b3 < distance_b && distance_b3 < distance_a)
		sb(b);
	if (distance_b2 < distance_a && distance_b2 < distance_b)
		do_rr_rrr(a, b, get_next_min_reverse(b, a->array[0]));
	else if (distance_b <= distance_a)
		do_rr_rrr(a, b, get_next_min(b, a->array[0]));
	else
	{
		if (b->array[0] > get_max(a))
			smart_rotate_a(a, b, get_min(a));
		else
			smart_rotate_a(a, b, get_min_big(a, b->array[0]));
	}
}

void	sort_push_a(t_stack *a, t_stack *b)
{
	while (b->size > 0)
	{
		do_cheapest_move(a, b);
		pa(a, b);
	}
	smart_rotate_a(a, b, get_min(a));
}

void	sort_big(t_stack *a, t_stack *b)
{
	move_to_b(a, b);
	sort_three(a);
	sort_push_a(a, b);
}
