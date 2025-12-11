/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nkuydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:08:11 by nkuydin           #+#    #+#             */
/*   Updated: 2025/11/25 10:18:11 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../42Libft/includes/libft.h"
# include <limits.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}	t_stack;

// swap
void	sa(t_stack *arr);
void	sb(t_stack *arr);
void	ss(t_stack *arr);

// push
void	pa(t_stack *arr);
void	pb(t_stack *arr);

// rotate
void	ra(t_stack *arr);
void	rb(t_stack *arr);
void	rr(t_stack *arr);

// reverse rotate
void	rra(t_stack *arr);
void	rrb(t_stack *arr);
void	rrr(t_stack *arr);

// small sort
void	small_sort(t_stack *arr);
void	sort_three(t_stack *arr);
void	sort_four(t_stack *arr);
void	sort_five(t_stack *arr);

// sorting utilities
void	bubble_sort(int *array, int size);
void	find_index(t_stack *arr, int *c);

// large sort
void	radix_sort(t_stack *arr);

// validation
void	validate_args(int argc, char **argv);
void	free_exit(t_stack *arr, char *msg);
void	exit_if_sorted_or_has_duplicate(t_stack *arr);
int		is_sorted(t_stack *arr);

// parsing
void	parse_args(int argc, char **argv, t_stack *arr, int *c);
char	*join_args(int argc, char **argv);

// main
void	init_stacks(int argc, char **argv, t_stack *arr);

#endif