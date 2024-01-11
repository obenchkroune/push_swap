/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 08:04:01 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/11 08:04:08 by obenchkr         ###   ########.fr       */
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
