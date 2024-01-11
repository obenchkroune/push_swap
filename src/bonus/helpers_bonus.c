/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:56:58 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/11 10:07:45 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	*malloc_check(void *ptr, t_stack *a, t_stack *b, int _exit)
{
	if (!ptr)
	{
		free(a);
		free(a->arr);
		free(b);
		free(b->arr);
		if (_exit)
			exit(1);
		return (NULL);
	}
	return (ptr);
}

