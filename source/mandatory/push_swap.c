/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 10:53:23 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/07 11:16:54 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_push_swap(t_stack **a, t_stack **b, int ac, char **av)
{
	int	i;
	int	j;

	*a = malloc(sizeof(t_stack));
	*b = malloc(sizeof(t_stack));
	(*a)->array = malloc(sizeof(int) * (ac - 1));
	(*b)->array = malloc(sizeof(int) * (ac - 1));
	(*a)->size = ac - 1;
	(*b)->size = 0;
	i = 0;
	j = 1;
	while (j < ac)
	{
		(*a)->array[i] = ft_atoi(av[j]);
		i++;
		j++;
	}
}

bool	check_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->array[i] > stack->array[i + 1])
			return (false);
		i++;
	}
	return (true);
}

void	cleanup_push_swap(t_stack *a, t_stack *b)
{
	free(a->array);
	free(b->array);
	free(a);
	free(b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	init_push_swap(&a, &b, ac, av);
	if (!check_sorted(a))
	{
		if (a->size == 2)
			ra(a);
		else if (a->size == 3)
			sort_three(a);
		else
			sort_big(a, b);
	}
	cleanup_push_swap(a, b);
	return (0);
}
