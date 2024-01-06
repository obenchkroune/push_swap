/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 23:29:09 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/06 02:41:53 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	printf("==================\n");
	while (i < stack->size)
	{
		printf("- %d\n", stack->array[i]);
		i++;
	}
	printf("==================\n");
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**numbers;

	if (ac < 2)
		return (0);
	fill_numbers(&numbers, ac, av);
	if (!numbers)
		return (EXIT_FAILURE);
	check_errors(numbers);
	init_stacks(&a, &b, numbers);
	if (!is_sorted(a))
		do_sort(a, b);
	print_stack(a);
	cleanup(a, b, numbers);
	return (0);
}
