/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   performance.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 10:53:12 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/07 15:27:48 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_distance(t_stack *s, int nbr)
{
	int	i;

	i = 0;
	while (i < s->size && s->array[i] != nbr)
		i++;
	return (i);
}

int	get_optimized_distance(t_stack *s, int nbr)
{
	int	i;

	i = 0;
	while (i < s->size && s->array[i] != nbr)
		i++;
	if (i <= s->size / 2)
		return (i);
	return (s->size - i);
}

int	get_next_min(t_stack *s, int nbr)
{
	int	i;

	i = 0;
	while (i < s->size)
	{
		if (s->array[i] < nbr)
			return (s->array[i]);
		i++;
	}
	return (get_min(s));
}

int	get_next_min_reverse(t_stack *s, int nbr)
{
	int	i;

	i = s->size - 1;
	while (i > 0)
	{
		if (s->array[i] < nbr)
			return (s->array[i]);
		i--;
	}
	return (get_min(s));
}

int	get_min_big(t_stack *s, int nbr)
{
	long	min_bigger;
	int		i;

	min_bigger = get_max(s);
	i = 0;
	while (i < s->size)
	{
		if (s->array[i] > nbr && (long)s->array[i] < min_bigger)
		{
			min_bigger = s->array[i];
		}
		i++;
	}
	return (min_bigger);
}

void	smart_rotate_a(t_stack *a, t_stack *b, int nbr)
{
	int	distance;
	

	distance = get_distance(a, nbr);
	if (distance <= a->size / 2)
	{
		while (a->array[0] != nbr)
			ra(a);
	}
	else
	{
		while (a->array[0] != nbr)
			rra(a);
	}
}

void	smart_rotate_b(t_stack *a, t_stack *b, int nbr)
{
	int	distance;

	distance = get_distance(b, nbr);
	if (distance <= b->size / 2)
	{
		while (b->array[0] != nbr)
			rb(b);
	}
	else
	{
		while (b->array[0] != nbr)
			rrb(b);
	}
}
