/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 23:29:09 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/03 02:22:30 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	cleanup(a, b, numbers);
	return (0);
}
