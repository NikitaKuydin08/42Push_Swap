/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nkuydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:01:29 by nkuydin           #+#    #+#             */
/*   Updated: 2025/11/13 21:29:07 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack *arr)
{
	int	i;
	int	j;
	int	z;

	i = arr->a[0];
	j = arr->a[1];
	z = arr->a[2];
	if (arr->size_a == 2 && arr->a[0] > arr->a[1])
		sa(arr);
	if (i > j && z > i && j < z)
		sa(arr);
	else if (z < i && z < j && i < j)
		rra(arr);
	else if (i > j && i > z && j < z)
		ra(arr);
	else if (j > i && j > z && i < z)
	{
		rra(arr);
		sa(arr);
	}
	else if (i > j && j > z)
	{
		ra(arr);
		sa(arr);
	}
}

void	sort_four(t_stack *arr)
{
	int	pos;

	pos = position_of_min(arr);
	rotate_to_top(arr, pos);
	pb(arr);
	sort_three(arr);
	pa(arr);
}

void	sort_five(t_stack *arr)
{
	int	pos;

	pos = position_of_min(arr);
	rotate_to_top(arr, pos);
	pb(arr);
	pos = position_of_min(arr);
	rotate_to_top(arr, pos);
	pb(arr);
	sort_three(arr);
	pa(arr);
	pa(arr);
}
