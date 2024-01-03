/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:50:28 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/03 01:58:39 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

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
	return (-1);
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

void	sort_4_plus(t_stack *a, t_stack *b)
{
	int	min;
	int	pos;

	while (a->size > 3)
	{
		min = get_min(a);
		pos = get_pos(a, min);
		if (pos == -1)
			exit(EXIT_FAILURE);
		if (pos < a->size / 2)
			while (a->array[0] != min)
				ra(a);
		else
			while (a->array[0] != min)
				rra(a);
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
		sort_4_plus(a, b);
}
