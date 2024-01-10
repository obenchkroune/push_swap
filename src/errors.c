/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:15:17 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/10 11:44:06 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(char **nbrs)
{
	int	i;
	int	j;

	i = 0;
	while (nbrs[i])
	{
		j = i + 1;
		while (nbrs[j])
		{
			if (ft_strncmp(nbrs[i], nbrs[j], 12) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_valid_number(char *nbr)
{
	int	i;

	i = 0;
	if (nbr[i] == '-' || nbr[i] == '+')
		i++;
	while (nbr[i])
	{
		if (!ft_isdigit(nbr[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_int_overflow(char *nbr)
{
	if (ft_strlen(nbr) < 10)
		return (0);
	if (ft_strlen(nbr) == 11 && ft_strncmp(nbr, "-2147483648", 12) <= 0)
		return (0);
	if (ft_strlen(nbr) == 10 && ft_strncmp(nbr, "2147483647", 11) <= 0)
		return (0);
	return (1);
}

static void	free_2d_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	check_errors(char **nbrs)
{
	int	i;
	int	err;

	err = 0;
	if (check_duplicate(nbrs))
		err = 1;
	i = 0;
	while (nbrs[i])
	{
		if (check_int_overflow(nbrs[i]) || !is_valid_number(nbrs[i]))
		{
			err = 1;
			break ;
		}
		i++;
	}
	if (err)
	{
		free_2d_tab(nbrs);
		ft_putendl_fd("Error", 1);
		exit(1);
	}
}
