/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:50:28 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/06 02:39:22 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	get_max(t_stack *stack)
{
	int	max;
	int	i;

	max = stack->array[0];
	i = 0;
	while (i < stack->size)
	{
		if (stack->array[i] > max)
			max = stack->array[i];
		i++;
	}
	return (max);
}

static int	get_min(t_stack *stack)
{
	int	min;
	int	i;

	min = stack->array[0];
	i = 0;
	while (i < stack->size)
	{
		if (stack->array[i] < min)
			min = stack->array[i];
		i++;
	}
	return (min);
}

static int	get_pos(t_stack *stack, int nbr)
{
	int	idx;

	idx = 0;
	while (idx < stack->size)
	{
		if (stack->array[idx] == nbr)
			return (idx);
		idx++;
	}
	return (0);
}

void	sort_3(t_stack *stack_a)
{
	int	a;
	int	b;
	int	c;

	a = stack_a->array[0];
	b = stack_a->array[1];
	c = stack_a->array[2];
	if (a > b && b < c && a < c)
		sa(stack_a);
	else if (a > b && b > c && a > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a > b && b < c && a > c)
		ra(stack_a);
	else if (a < b && b > c && a < c)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a);
}

int	get_median(t_stack *stack)
{
	int		min;
	int		max;
	int		median;
	int		i;
	int		j;

	min = get_min(stack);
	max = get_max(stack);
	i = 0;
	while (i < stack->size)
	{
		if (stack->array[i] > max && stack->array[i] < min)
			max = stack->array[i];
		i++;
	}
	median = (min + max) / 2;
	j = get_pos(stack, median);
	return (j);
}

void	merge_sort(t_stack *a, t_stack *b)
{
	int	median;

	median = get_median(a);
	while (a->size > 3)
	{
		if (a->array[0] > median)
		{
			pb(a, b);
			rb(b);
		}
		else
			pb(a, b);
	}
	sort_3(a);
	while (b->size > 0)
		pa(a, b);
}

void	do_sort(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sa(a);
	else if (a->size == 3)
		sort_3(a);
	else
		merge_sort(a, b);
}
