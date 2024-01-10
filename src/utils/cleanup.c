/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:02:06 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/10 11:18:33 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cleanup(t_stack *a, t_stack *b, char **nbrs)
{
	int	i;

	i = 0;
	while (nbrs[i])
		free(nbrs[i++]);
	free(nbrs);
	cleanup_stack(a);
	cleanup_stack(b);
}

void	cleanup_stack(t_stack *stack)
{
	if (stack != NULL)
	{
		free(stack->arr);
		stack->arr = NULL;
		free(stack);
		stack = NULL;
	}
}
