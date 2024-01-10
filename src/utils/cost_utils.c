/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:09:42 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/09 18:56:00 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*copy_stack(t_stack *stack)
{
	t_stack	*result;
	int		*arr;

	result = malloc(sizeof(t_stack));
	if (!result)
		return (NULL);
	arr = malloc(sizeof(int) * stack->max_size);
	if (!arr)
	{
		free(result);
		return (NULL);
	}
	ft_memmove(result, stack, sizeof(t_stack));
	ft_memmove(arr, stack->arr, sizeof(int) * stack->size);
	result->arr = arr;
	return (result);
}
