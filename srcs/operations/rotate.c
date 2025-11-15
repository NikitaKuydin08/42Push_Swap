/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nkuydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 17:26:46 by nkuydin           #+#    #+#             */
/*   Updated: 2025/10/31 00:25:38 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ra - Shift up all elements of stack a by 1
// The first element[0] becomes the last one[size_a - 1] of stack_a
// store the first element of stack a in a temporary int value
// shift all values upwards by one, store the temporary value at 
// the opened value

#include "../includes/push_swap.h"

static void	rotate(int *array, int size)
{
	int	temp;
	int	i;

	i = 0;
	if (size <= 0)
		return ;
	temp = array[0];
	while (i < size - 1)
	{
		array[i] = array[i + 1];
		i++;
	}
	array[size - 1] = temp;
}

void	ra(t_stack *arr)
{
	rotate(arr->a, arr->size_a);
	ft_putendl_fd("ra\n", 1);
}

void	rb(t_stack *arr)
{
	rotate(arr->b, arr->size_b);
	ft_putendl_fd("rb\n", 1);
}

void	rr(t_stack *arr)
{
	rotate(arr->a, arr->size_a);
	rotate(arr->b, arr->size_b);
	ft_putendl_fd("rr\n", 1);
}

// void	ra(t_stack *arr)
// {
// 	int	temp;
// 	int	i;

// 	i = 0;
// 	if (arr->size_a <= 0)
// 		return ;
// 	temp = arr->a[0];
// 	while (i < arr->size_a - 1)
// 	{
// 		arr->a[i] = arr->a[i + 1];
// 		i++;
// 	}
// 	arr->a[arr->size_a - 1] = temp;
// 	ft_putendl_fd("ra", 1);
// }

// void	rb(t_stack *arr)
// {
// 	int	temp;
// 	int	i;

// 	i = 0;
// 	if (arr->size_b <= 0)
// 		return ;
// 	temp = arr->b[0];
// 	while (i < arr->size_b - 1)
// 	{
// 		arr->b[i] = arr->b[i + 1];
// 		i++;
// 	}
// 	arr->b[arr->size_b - 1] = temp;
// 	ft_putendl_fd("rb", 1);
// }

// void	rr(t_stack *arr)
// {
// 	int	temp;

// 	if (arr->size_a > 0)
// 	{
// 		temp = arr->a[0];
// 		ft_memmove(arr->a, arr->a + 1, sizeof(int) * (arr->size_a - 1));
// 		arr->a[arr->size_a - 1] = temp;
// 	}
// 	if (arr->size_b > 0)
// 	{
// 		temp = arr->b[0];
// 		ft_memmove(arr->b, arr->b + 1, sizeof(int) * (arr->size_b - 1));
// 		arr->b[arr->size_b - 1] = temp;
// 	}
// 	ft_putendl_fd("rr", 1);
// }