/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_median_push_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:01:32 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/10 12:40:53 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	*quick_sort(t_stack *stack)
{
	int	*sorted;
	int	i;
	int	j;

	sorted = (int *)malloc(sizeof(int) * stack->size);
	ft_memcpy(sorted, stack->arr, sizeof(int) * stack->size);
	i = 0;
	while (i < stack->size)
	{
		j = i + 1;
		while (j < stack->size)
		{
			if (sorted[i] > sorted[j])
				ft_swap(&sorted[i], &sorted[j]);
			j++;
		}
		i++;
	}
	return (sorted);
}

int	get_median(t_stack *stack)
{
	int	*sorted;
	int	median;

	sorted = quick_sort(stack);
	median = sorted[stack->size / 2];
	free(sorted);
	return (median);
}

void	push_median_b(t_stack *a, t_stack *b)
{
	int	median;

	while (a->size > 3 && !is_sorted(a))
	{
		median = get_median(a);
		while (a->arr[0] > median)
			ra(a);
		pb(a, b);
	}
}
