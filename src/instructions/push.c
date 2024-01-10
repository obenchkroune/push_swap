/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:32:15 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/09 15:34:34 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	push(a, b);
	ft_putendl_fd("pa", 1);
}

void	pb(t_stack *a, t_stack *b)
{
	push(b, a);
	ft_putendl_fd("pb", 1);
}
