/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 17:16:20 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/07 13:55:14 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include <stdio.h>

// stack data structure
typedef struct s_stack
{
	int	*array;
	int	size;
}	t_stack;

void	init_push_swap(t_stack **a, t_stack **b, int ac, char **av);

// moves
void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	push(t_stack *src, t_stack *dest);
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

void	move_to_b(t_stack *a, t_stack *b);
void	do_cheapest_move(t_stack *a, t_stack *b);
void	sort_push_a(t_stack *a, t_stack *b);
void	sort_three(t_stack *stack);
void	sort_big(t_stack *a, t_stack *b);

// utils
int		get_min(t_stack *stack);
int		get_max(t_stack *stack);
int		*sort_arr(t_stack *stack);
int		get_median(t_stack *stack);
int		get_distance(t_stack *s, int nbr);
int		get_next_min(t_stack *s, int nbr);
int		get_next_min_reverse(t_stack *s, int nbr);
int		get_min_big(t_stack *s, int nbr);
int		get_b_distance(t_stack *a, t_stack *b);
int		get_a_distance(t_stack *a, t_stack *b);
int		get_min(t_stack *stack);
int		get_max(t_stack *stack);
int		get_median(t_stack *stack);
void	smart_rotate_a(t_stack *a, t_stack *b, int nbr);
void	smart_rotate_b(t_stack *a, t_stack *b, int nbr);
int		get_optimized_distance(t_stack *s, int nbr);

#endif
