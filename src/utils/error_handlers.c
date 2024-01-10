/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:01:19 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/10 11:07:38 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cleanup_exit(t_stack *a, t_stack *b)
{
	free(a);
	free(a->arr);
	free(b);
	free(b->arr);
	exit(1);
}

void	*malloc_check(void *ptr, t_stack *a, t_stack *b, int _exit)
{
	if (!ptr)
	{
		free(a);
		free(a->arr);
		free(b);
		free(b->arr);
		if (_exit)
			exit(1);
		return (NULL);
	}
	return (ptr);
}
