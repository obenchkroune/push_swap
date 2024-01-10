/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:58:51 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/10 11:37:33 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_numbers(char ***numbers, int ac, char **av)
{
	char	**result;
	int		i;

	if (ac == 2)
		result = ft_split(av[1], ' ');
	else
	{
		result = malloc(sizeof(numbers) * ac);
		if (!result)
			exit(1);
		i = 0;
		while (i < ac - 1)
		{
			result[i] = ft_strdup(av[i + 1]);
			i++;
		}
		result[i] = NULL;
	}
	*numbers = result;
}

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
