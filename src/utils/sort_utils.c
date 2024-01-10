/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:15:42 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/09 16:42:29 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->arr[i] > stack->arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	get_min(t_stack *stack)
{
	int	min;
	int	i;

	if (stack->size < 1)
		return (INT_MIN);
	min = stack->arr[0];
	i = 0;
	while (i < stack->size)
	{
		if (stack->arr[i] < min)
			min = stack->arr[i];
		i++;
	}
	return (min);
}

int	get_max(t_stack *stack)
{
	int	max;
	int	i;

	if (stack->size < 1)
		return (INT_MIN);
	max = stack->arr[0];
	i = 0;
	while (i < stack->size)
	{
		if (stack->arr[i] > max)
			max = stack->arr[i];
		i++;
	}
	return (max);
}

int	get_head(t_stack *stack)
{
	return (stack->arr[0]);
}

int	get_tail(t_stack *stack)
{
	return (stack->arr[stack->size - 1]);
}
