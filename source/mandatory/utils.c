/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 23:31:25 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/03 02:16:41 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	array_size(char **arr)
{
	int	count;

	count = 0;
	while (arr[count] != NULL)
	{
		count++;
	}
	return (count);
}

void	init_stacks(t_stack **a, t_stack **b, char **numbers)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
		exit(EXIT_FAILURE);
	stack_a->size = array_size(numbers);
	stack_a->array = malloc(sizeof(int) * stack_a->size);
	stack_b->size = 0;
	stack_b->array = malloc(sizeof(int) * stack_a->size);
	if (!stack_a->array || !stack_b->array)
		exit(EXIT_FAILURE);
	i = 0;
	while (numbers[i] != NULL)
	{
		stack_a->array[i] = ft_atoi(numbers[i]);
		i++;
	}
	*a = stack_a;
	*b = stack_b;
}

void	cleanup(t_stack *a, t_stack *b, char **numbers)
{
	int	i;

	free(a->array);
	free(b->array);
	free(a);
	free(b);
	i = 0;
	while (numbers[i] != NULL)
		free(numbers[i++]);
	free(numbers);
}

void	fill_numbers(char ***n_ptr, int ac, char **av)
{
	int	i;
	int	j;

	if (ac == 2)
		*n_ptr = ft_split(av[1], ' ');
	else
	{
		i = 0;
		j = 1;
		*n_ptr = malloc(sizeof(char *) * ac);
		while (av[j] != NULL)
			(*n_ptr)[i++] = ft_strdup(av[j++]);
		(*n_ptr)[i] = NULL;
	}
}

bool	is_sorted(t_stack *stack)
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
