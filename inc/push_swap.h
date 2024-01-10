/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:22:33 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/10 14:38:19 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "libft.h"
# include <stdbool.h>
# include <stdio.h>
# include <limits.h>
# include <stdarg.h>

# define ROTATIONS_CONST 20

typedef struct s_stack
{
	int	*arr;
	int	size;
	int	max_size;
}	t_stack;

typedef struct s_costs
{
	int	ra_cost;
	int	rra_cost;
	int	*ra_rb_cost;
	int	*ra_rrb_cost;
	int	*rra_rrb_cost;
}	t_costs;

char	*get_next_line(int fd);

void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

void	do_ra(t_stack *a, t_stack *b);
void	do_rra(t_stack *a, t_stack *b);
void	do_ra_rb(t_stack *a, t_stack *b, int *rotations);
void	do_ra_rrb(t_stack *a, t_stack *b, int *rotations);
void	do_rra_rrb(t_stack *a, t_stack *b, int *rotations);

void	init_stacks(t_stack **a, t_stack **b, char **numbers);
void	cleanup_stack(t_stack *stack);
void	cleanup(t_stack *a, t_stack *b, char **nbrs);
void	*malloc_check(void *ptr, t_stack *a, t_stack *b, int exit);
void	cleanup_exit(t_stack *a, t_stack *b);
int		is_sorted(t_stack *stack);
void	sort_stack(t_stack *a, t_stack *b);
void	push(t_stack *dst, t_stack *src);
void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
int		get_max(t_stack *stack);
int		get_min(t_stack *stack);
void	push_median_b(t_stack *a, t_stack *b);
int		check_position(t_stack *a, t_stack *b);
void	rotate_push_a(t_stack *a, t_stack *b);
int		get_head(t_stack *stack);
int		get_tail(t_stack *stack);
t_stack	*copy_stack(t_stack *stack);
int		ft_max(int a, int b);
int		ft_min(int a, int b);

int		get_ra_cost(t_stack *a, t_stack *b);
int		get_rra_cost(t_stack *a, t_stack *b);
int		*get_ra_rb_cost(t_stack *a, t_stack *b);
int		*get_ra_rrb_cost(t_stack *a, t_stack *b);
int		*get_rra_rrb_cost(t_stack *a, t_stack *b);
void	check_errors(char **nbrs);

#endif