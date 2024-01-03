/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errrors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 23:35:55 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/03 02:24:15 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

bool	is_overflowing_int(char *nbr)
{
	size_t	max_length;
	char	*template;

	max_length = 10;
	template = "2147483647";
	if (nbr[0] == '-')
	{
		template = "2147483648";
		nbr++;
	}
	if (ft_strlen(nbr) < max_length)
		return (false);
	if (ft_strncmp(template, nbr, 10) < 0)
		return (true);
	return (false);
}

bool	is_valid_number(char *nbr)
{
	if (is_overflowing_int(nbr))
		return (false);
	if (*nbr == '-')
		nbr++;
	if (*nbr == '\0')
		return (false);
	while (*nbr)
	{
		if (!ft_isdigit(*nbr))
		{
			return (false);
		}
		nbr++;
	}
	return (true);
}

void	check_duplicate(char **numbers)
{
	int	i;
	int	j;

	i = 0;
	while (numbers[i] != NULL)
	{
		j = i + 1;
		while (numbers[j] != NULL)
		{
			if (ft_strncmp(numbers[j], numbers[i], 11) == 0)
			{
				exit_error();
			}
			j++;
		}
		i++;
	}
}

void	check_errors(char **numbers)
{
	int	idx;

	idx = 0;
	check_duplicate(numbers);
	while (numbers[idx] != NULL)
	{
		if (!is_valid_number(numbers[idx]))
			exit_error();
		idx++;
	}
}
