/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 23:29:57 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/03 01:14:59 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	int	temp;

	if (stack->size < 2)
		return ;
	temp = stack->array[0];
	stack->array[0] = stack->array[1];
	stack->array[1] = temp;
}

void	sa(t_stack *a)
{
	swap(a);
	ft_putendl_fd("sa", STDOUT_FILENO);
}

void	sb(t_stack *b)
{
	swap(b);
	ft_putendl_fd("sb", STDOUT_FILENO);
}
