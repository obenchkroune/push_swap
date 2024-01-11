/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:43:49 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/11 10:06:59 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H

# define PUSH_SWAP_BONUS_H

# include "libft.h"

typedef struct s_stack
{
	int	*arr;
	int	size;
	int	max_size;
}	t_stack;

char	*get_next_line(int fd);
void	swap(t_stack *a);
void	push(t_stack *a, t_stack *b);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	run_instructions(t_stack *a, t_stack *b, char **numbers);
void	parse_numbers(char ***nbrs, int argc, char **argv);
void	check_errors(char **numbers);
void	init_stacks(t_stack **a, t_stack **b, char **numbers);
void	cleanup(t_stack *a, t_stack *b, char **nbrs);
void	run_instructions(t_stack *a, t_stack *b, char **numbers);
int		is_sorted(t_stack *stack);
void	cleanup_stack(t_stack *stack);
void	*malloc_check(void *ptr, t_stack *a, t_stack *b, int _exit);

#endif