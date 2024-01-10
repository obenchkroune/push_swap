/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_push_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:18:30 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/10 12:26:15 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_cheapest_move(t_costs costs, t_stack *a, t_stack *b)
{
	int	min;

	min = ft_min(costs.rra_cost, \
				ft_min(costs.ra_rrb_cost[2], costs.ra_rb_cost[0]));
	if (costs.rra_rrb_cost[2] <= ft_min(costs.ra_cost, min))
		do_rra_rrb(a, b, costs.rra_rrb_cost);
	else if (costs.ra_cost <= min)
		do_ra(a, b);
	else if (costs.rra_cost <= \
			ft_min(costs.ra_rrb_cost[2], costs.ra_rb_cost[0]))
		do_rra(a, b);
	else if (costs.ra_rrb_cost[2] <= costs.ra_rb_cost[0])
		do_ra_rrb(a, b, costs.ra_rrb_cost);
	else
		do_ra_rb(a, b, costs.ra_rb_cost);
}

void	rotate_push_a(t_stack *a, t_stack *b)
{
	t_costs	costs;

	if (!check_position(a, b))
	{
		costs.ra_cost = get_ra_cost(a, b);
		costs.rra_cost = get_rra_cost(a, b);
		costs.ra_rb_cost = get_ra_rb_cost(a, b);
		costs.ra_rrb_cost = get_ra_rrb_cost(a, b);
		costs.rra_rrb_cost = get_rra_rrb_cost(a, b);
		do_cheapest_move(costs, a, b);
		free(costs.ra_rb_cost);
		free(costs.ra_rrb_cost);
		free(costs.rra_rrb_cost);
	}
	pa(a, b);
}
