/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nkuydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:23:37 by nkuydin           #+#    #+#             */
/*   Updated: 2025/11/22 16:05:48 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	bubble_sort(int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	temp = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
			}
			j++;
		}
		i++;
	}
}

// void	sort_three_b(t_stack *arr)
// {
// 	int	i;
// 	int	j;
// 	int	z;

// 	i = arr->b[0];
// 	j = arr->b[1];
// 	z = arr->b[2];
// 	if (arr->size_b == 2 && arr->b[0] < arr->b[1])
// 		sb(arr);
// 	if (i > j && z > i && i < z)
// 		rrb(arr);
// 	else if (i > z && z < j && i < j)
// 		sb(arr);
// 	else if (j > i && j > z && i < z)
// 		rb(arr);
// 	else if (i > j && i > z && j < z)
// 	{
// 		rrb(arr);
// 		sb(arr);
// 	}
// 	else if (z > j && j > i)
// 	{
// 		sb(arr);
// 		rrb(arr);
// 	}
// }

// void	sort_three_b(t_stack *arr)
// {
// 	int	i = arr->b[0];
// 	int	j = arr->b[1];
// 	int	z = arr->b[2];

// 	// Case 1: already descending
// 	if (i > j && j > z)
// 		return ;
// 	// Case 2: middle is biggest
// 	if (j > i && j > z)
// 	{
// 		if (i > z)
// 			rb(arr);       // rotate
// 		else
// 		{
// 			sb(arr);
// 			rrb(arr);
// 		}
// 	}
// 	// Case 3: bottom is biggest
// 	else if (z > i && z > j)
// 	{
// 		if (i > j)
// 		{
// 			sb(arr);
// 			rb(arr);
// 		}
// 		else
// 			rrb(arr);
// 	}
// }

// void	sort_three_b(t_stack *arr)
// {
// 	int	i;
// 	int	j;
// 	int	z;

// 	i = arr->b[0];
// 	j = arr->b[1];
// 	z = arr->b[2];
	
// 	// Goal: largest on top (i), smallest on bottom (z)
// 	// i > j > z when done
	
// 	if (i < j && j < z)  // 1 2 3 -> need 3 2 1
// 	{
// 		sb(arr);
// 		rb(arr);
// 	}
// 	else if (i < j && j > z && i > z)  // 2 3 1 -> need 3 2 1
// 		sb(arr);
// 	else if (i < j && j > z && i < z)  // 1 3 2 -> need 3 2 1
// 		rb(arr);
// 	else if (i > j && j < z && i < z)  // 2 1 3 -> need 3 2 1
// 	{
// 		rrb(arr);
// 		sb(arr);
// 	}
// 	else if (i > j && j > z)  // 3 2 1 already sorted
// 		return;
// 	else if (i > j && j < z && i > z)  // 3 1 2 -> need 3 2 1
// 		rrb(arr);
// }
