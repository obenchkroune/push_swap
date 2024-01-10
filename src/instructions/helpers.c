/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:19:40 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/09 18:13:28 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *dst, t_stack *src)
{
	int	temp;
	int	i;

	if (src->size < 1)
		return ;
	temp = src->arr[0];
	i = 0;
	src->size--;
	while (i < src->size)
	{
		src->arr[i] = src->arr[i + 1];
		i++;
	}
	i = dst->size;
	while (i > 0)
	{
		dst->arr[i] = dst->arr[i - 1];
		i--;
	}
	dst->arr[0] = temp;
	dst->size++;
}

void	swap(t_stack *stack)
{
	int	temp;

	if (stack->size < 2)
		return ;
	temp = stack->arr[0];
	stack->arr[0] = stack->arr[1];
	stack->arr[1] = temp;
}

void	rotate(t_stack *stack)
{
	int	i;
	int	temp;

	if (stack->size < 2)
		return ;
	i = 0;
	temp = stack->arr[0];
	while (i < stack->size - 1)
	{
		stack->arr[i] = stack->arr[i + 1];
		i++;
	}
	stack->arr[i] = temp;
}

void	reverse_rotate(t_stack *stack)
{
	int	i;
	int	temp;

	i = stack->size - 1;
	temp = stack->arr[i];
	while (i > 0)
	{
		stack->arr[i] = stack->arr[i - 1];
		i--;
	}
	stack->arr[i] = temp;
}
