/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 01:28:43 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/03 01:29:40 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	rotate(a);
	ft_putendl_fd("ra", STDOUT_FILENO);
}

void	rra(t_stack *a)
{
	reverse_rotate(a);
	ft_putendl_fd("rra", STDOUT_FILENO);
}
