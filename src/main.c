/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:58:51 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/11 08:03:36 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**numbers;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	parse_numbers(&numbers, argc, argv);
	check_errors(numbers);
	init_stacks(&a, &b, numbers);
	if (!is_sorted(a))
		sort_stack(a, b);
	cleanup(a, b, numbers);
	return (0);
}
