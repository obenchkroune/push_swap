/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 10:53:31 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/07 15:31:38 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	get_median(t_stack *stack)
{
	int	median;
	int	*sorted;

	sorted = sort_arr(stack);
	median = sorted[stack->size / 2];
	free(sorted);
	return (median);
}

static void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	*sort_arr(t_stack *stack)
{
	int	*sorted;
	int	i;

	sorted = malloc(sizeof(int) * stack->size);
	if (!sorted)
		return (NULL);
	i = 0;
	while (i < stack->size)
	{
		sorted[i] = stack->array[i];
		i++;
	}
	i = 0;
	while (i < stack->size - 1)
	{
		if (sorted[i] > sorted[i + 1])
		{
			ft_swap(&sorted[i], &sorted[i + 1]);
			i = 0;
		}
		else
			i++;
	}
	return (sorted);
}

int	get_min(t_stack *stack)
{
	int	min;
	int	i;

	min = INT_MAX;
	i = 0;
	while (i < stack->size)
	{
		if (stack->array[i] < min)
			min = stack->array[i];
		i++;
	}
	return (min);
}

int	get_max(t_stack *stack)
{
	int	max;
	int	i;

	if (stack->size == 0)
		return (INT_MAX);
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
