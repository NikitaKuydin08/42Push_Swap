/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nkuydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:01:29 by nkuydin           #+#    #+#             */
/*   Updated: 2025/11/25 13:24:06 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	small_sort(t_stack *arr)
{
	if (arr->size_a == 2)
		sa(arr);
	else if (arr->size_a == 3)
		sort_three(arr);
	else if (arr->size_a == 4)
		sort_four(arr);
	else if (arr->size_a == 5)
		sort_five(arr);
}

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

int	get_min_idx(t_stack *arr)
{
	int	pos_of_min;
	int	i;

	i = 1;
	pos_of_min = 0;
	while (i < arr->size_a)
	{
		if (arr->a[i] < arr->a[pos_of_min])
			pos_of_min = i;
		i++;
	}
	return (pos_of_min);
}

void	sort_four(t_stack *arr)
{
	int	pos_of_min;

	pos_of_min = get_min_idx(arr);
	if (pos_of_min <= arr->size_a / 2)
	{
		while (pos_of_min > 0)
		{
			ra(arr);
			pos_of_min--;
		}
	}
	else
	{
		while (pos_of_min > 0)
		{
			if (pos_of_min == arr->size_a - 1)
				pos_of_min = 0;
			rra(arr);
			pos_of_min--;
		}
	}
	pb(arr);
	sort_three(arr);
	pa(arr);
}

void	sort_five(t_stack *arr)
{
	int	pos_of_min;

	pos_of_min = get_min_idx(arr);
	if (pos_of_min <= arr->size_a / 2)
	{
		while (pos_of_min > 0)
		{
			ra(arr);
			pos_of_min--;
		}
	}
	else
	{
		while (pos_of_min > 0)
		{
			if (pos_of_min == arr->size_a - 1)
				pos_of_min = 0;
			rra(arr);
			pos_of_min--;
		}
	}
	pb(arr);
	sort_four(arr);
	pa(arr);
}
