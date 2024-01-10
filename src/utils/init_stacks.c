/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:00:08 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/10 12:49:28 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_tabsize(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	init_stacks(t_stack **stack_a, t_stack **stack_b, char **numbers)
{
	int		i;
	t_stack	*a;
	t_stack	*b;
	int		size;

	a = NULL;
	b = NULL;
	size = ft_tabsize(numbers);
	a = malloc_check(malloc(sizeof(t_stack)), a, b, 1);
	b = malloc_check(malloc(sizeof(t_stack)), a, b, 1);
	a->arr = malloc_check(malloc(sizeof(int) * size), a, b, 1);
	a->size = size;
	b->arr = malloc_check(malloc(sizeof(int) * size), a, b, 1);
	b->size = 0;
	i = 0;
	while (i < size)
	{
		a->arr[i] = ft_atoi(numbers[i]);
		i++;
	}
	a->max_size = size;
	b->max_size = size;
	*stack_a = a;
	*stack_b = b;
}
