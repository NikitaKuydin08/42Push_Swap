/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nkuydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 07:41:18 by nkuydin           #+#    #+#             */
/*   Updated: 2025/11/25 12:45:51 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	int	size;

	i = 0;
	size = arr->size_a;
	max_bits = get_max(arr);
	while (i < max_bits && !is_sorted(arr))
	{
		j = 0;
		while (j < size)
		{
			if ((arr->a[0] >> i) & 1)
				ra(arr);
			else
				pb(arr);
			j++;
		}
		while (arr->size_b > 0)
			pa(arr);
		i++;
	}
}
