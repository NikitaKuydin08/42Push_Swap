/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nkuydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:25:49 by nkuydin           #+#    #+#             */
/*   Updated: 2025/10/31 00:25:52 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(int *array, int size)
{
	int	temp;

	if (size <= 0)
		return ;
	temp = array[0];
	array[0] = array[1];
	array[1] = temp;
}

void	sa(t_stack *arr)
{
	swap(arr->a, arr->size_a);
	ft_putendl_fd("sa\n", 1);
}

void	sb(t_stack *arr)
{
	swap(arr->b, arr->size_b);
	ft_putendl_fd("sb\n", 1);
}

void	ss(t_stack *arr)
{
	swap(arr->a, arr->size_a);
	swap(arr->b, arr->size_b);
	ft_putendl_fd("ss\n", 1);
}

// void	sa(t_stack *arr)
// {
// 	int	tmp;

// 	if (arr->size_a <= 0)
// 		return ;
// 	tmp = arr->a[0];
// 	arr->a[0] = arr->a[1];
// 	arr->a[1] = tmp;
// 	ft_putendl_fd("sa", 1);
// }

// void	sb(t_stack *arr)
// {
// 	int	tmp;

// 	if (arr->size_b <= 0)
// 		return ;
// 	tmp = arr->b[0];
// 	arr->b[0] = arr->b[1];
// 	arr->b[1] = tmp;
// 	ft_putendl_fd("sb", 1);
// }

// void	ss(t_stack *arr)
// {
// 	int	tmp;

// 	if (arr->size_a > 0)
// 	{
// 		tmp = arr->a[0];
// 		arr->a[0] = arr->a[1];
// 		arr->a[1] = tmp;
// 	}
// 	if (arr->size_b > 0)
// 	{
// 		tmp = arr->b[0];
// 		arr->b[0] = arr->b[1];
// 		arr->b[1] = tmp;
// 	}
// 	ft_putendl_fd("ss", 1);
// }
