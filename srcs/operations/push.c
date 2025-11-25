/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nkuydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:41:45 by nkuydin           #+#    #+#             */
/*   Updated: 2025/10/31 00:25:11 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_stack *arr)
{
	int	i;

	if (arr->size_b <= 0)
		return ;
	i = arr->size_a;
	while (i-- > 0)
		arr->a[i + 1] = arr->a[i];
	arr->a[0] = arr->b[0];
	arr->size_b--;
	i = 0;
	while (i < arr->size_b)
	{
		arr->b[i] = arr->b[i + 1];
		i++;
	}
	arr->size_a++;
	ft_putendl_fd("pa\n", 1);
}

void	pb(t_stack *arr)
{
	int	i;

	if (arr->size_a <= 0)
		return ;
	i = arr->size_b;
	while (i-- > 0)
		arr->b[i + 1] = arr->b[i];
	arr->b[0] = arr->a[0];
	arr->size_a--;
	i = 0;
	while (i < arr->size_a)
	{
		arr->a[i] = arr->a[i + 1];
		i++;
	}
	arr->size_b++;
	ft_putendl_fd("pb\n", 1);
}
