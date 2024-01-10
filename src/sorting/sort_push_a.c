/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_push_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:18:30 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/10 11:43:47 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_ra_rb(t_stack *a, t_stack *b, int *rotations)
{
	int	moves;
	int	ra_moves;
	int	rb_moves;

	ra_moves = rotations[0];
	rb_moves = rotations[1];
	while (ra_moves > 0 && rb_moves > 0)
	{
		rr(a, b);
		ra_moves--;
		rb_moves--;
	}
	while (ra_moves > 0)
	{
		ra(a);
		ra_moves--;
	}
	while (rb_moves > 0)
	{
		rb(b);
		rb_moves--;
	}
}

void	do_rra_rrb(t_stack *a, t_stack *b, int *rotations)
{
	int	moves;
	int	rra_moves;
	int	rrb_moves;

	rra_moves = rotations[0];
	rrb_moves = rotations[1];
	while (rra_moves > 0 && rrb_moves > 0)
	{
		rrr(a, b);
		rra_moves--;
		rrb_moves--;
	}
	while (rra_moves > 0)
	{
		rra(a);
		rra_moves--;
	}
	while (rrb_moves > 0)
	{
		rrb(b);
		rrb_moves--;
	}
}

void	do_ra_rrb(t_stack *a, t_stack *b, int *rotations)
{
	while (rotations[0]--)
		ra(a);
	while (rotations[1]--)
		rrb(b);
}

void	do_cheapest_move(t_costs costs, t_stack *a, t_stack *b)
{
	int	min;

	min = ft_min(costs.rra_cost, \
				ft_min(costs.ra_rrb_cost[2], costs.ra_rb_cost[0]));
	if (costs.rra_rrb_cost[2] <= ft_min(costs.ra_cost, min))
		do_rra_rrb(a, b, costs.rra_rrb_cost);
	else if (costs.ra_cost <= min)
		while (!check_position(a, b))
			ra(a);
	else if (costs.rra_cost <= \
			ft_min(costs.ra_rrb_cost[2], costs.ra_rb_cost[0]))
		while (!check_position(a, b))
			rra(a);
	else if (costs.ra_rrb_cost[2] <= costs.ra_rb_cost[0])
		do_ra_rrb(a, b, costs.ra_rrb_cost);
	else
		do_ra_rb(a, b, costs.ra_rb_cost);
}

void	sort_push_a(t_stack *a, t_stack *b)
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
