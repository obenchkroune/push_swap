/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 01:23:00 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/03 02:16:00 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack)
{
	int	temp;
	int	i;

	if (stack->size < 2)
		return ;
	i = 0;
	temp = stack->array[0];
	while (i < stack->size - 1)
	{
		stack->array[i] = stack->array[i + 1];
		i++;
	}
	stack->array[i] = temp;
}

void	reverse_rotate(t_stack *stack)
{
	int	temp;
	int	i;

	if (stack->size < 2)
		return ;
	i = stack->size - 1;
	temp = stack->array[i];
	while (i > 0)
	{
		stack->array[i] = stack->array[i - 1];
		i--;
	}
	stack->array[i] = temp;
}

void	push(t_stack *src, t_stack *dest)
{
	if (src->size == 0)
		return ;
	dest->array[dest->size] = src->array[0];
	dest->size++;
	reverse_rotate(dest);
	rotate(src);
	src->size--;
}
