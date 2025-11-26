/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nkuydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 07:41:18 by nkuydin           #+#    #+#             */
/*   Updated: 2025/11/26 16:56:09 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_b(t_stack *arr, int max_bits, int next_bit)
{
	int	i;

	i = arr->size_b;
	while (i-- && next_bit < max_bits && !is_sorted(arr))
	{
		if ((arr->b[0] >> next_bit) & 1)
			pa(arr);
		else
			rb(arr);
	}
	if (is_sorted(arr))
		while (arr->size_b > 0)
			pa(arr);
}

int	get_max(t_stack *arr)
{
	int	max_num;
	int	max_bits;
	int	i;

	i = 1;
	max_bits = 0;
	max_num = arr->a[0];
	while (i < arr->size_a)
	{
		if (arr->a[i] > max_num)
			max_num = arr->a[i];
		i++;
	}
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack *arr)
{
	int	i;
	int	j;
	int	max_bits;

	i = 0;
	max_bits = get_max(arr);
	while (i < max_bits)
	{
		j = arr->size_a;
		while (j-- && !is_sorted(arr))
		{
			if ((arr->a[0] >> i) & 1)
				ra(arr);
			else
				pb(arr);
		}
		sort_b(arr, max_bits, i + 1);
		i++;
	}
	while (arr->size_b > 0)
		pa(arr);
}

// void	radix_sort(t_stack *arr)
// {
// 	int	i;
// 	int	j;
// 	int	max_bits;
// 	int	size;

// 	i = 0;
// 	size = arr->size_a;
// 	max_bits = get_max(arr);
// 	while (i < max_bits && !is_sorted(arr))
// 	{
// 		j = 0;
// 		while (j < size)
// 		{
// 			if ((arr->a[0] >> i) & 1)
// 				ra(arr);
// 			else
// 				pb(arr);
// 			j++;
// 		}
// 		while (arr->size_b > 0)
// 			pa(arr);
// 		i++;
// 	}
// }
