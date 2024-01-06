/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 17:16:20 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/06 02:21:33 by obenchkr         ###   ########.fr       */
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

// operations
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	push(t_stack *src, t_stack *dest);

void	sa(t_stack *a);
void	sb(t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);

void	fill_numbers(char ***n_ptr, int ac, char **av);
void	init_stacks(t_stack **a, t_stack **b, char **numbers);
void	cleanup(t_stack *a, t_stack *b, char **numbers);
bool	is_sorted(t_stack *stack);
void	do_sort(t_stack *a, t_stack *b);
void	check_errors(char **av);

// sorting
void	sort_3(t_stack *stack_a);
void	merge_sort(t_stack *a, t_stack *b);

#endif
