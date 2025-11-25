/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nkuydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 19:25:43 by nkuydin           #+#    #+#             */
/*   Updated: 2025/10/31 00:25:24 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rev_rotate(int *array, int size)
{
	int	temp;
	int	i;

	if (size <= 1)
		return ;
	i = size - 2;
	temp = array[size - 1];
	while (i >= 0)
	{
		array[i + 1] = array[i];
		i--;
	}
	array[0] = temp;
}

void	rra(t_stack *arr)
{
	rev_rotate(arr->a, arr->size_a);
	ft_putendl_fd("rra\n", 1);
}

void	rrb(t_stack *arr)
{
	rev_rotate(arr->b, arr->size_b);
	ft_putendl_fd("rrb\n", 1);
}

void	rrr(t_stack *arr)
{
	rev_rotate(arr->a, arr->size_a);
	rev_rotate(arr->b, arr->size_b);
	ft_putendl_fd("rrr\n", 1);
}
