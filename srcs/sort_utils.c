/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nkuydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:23:37 by nkuydin           #+#    #+#             */
/*   Updated: 2025/11/26 15:03:55 by nkuydin          ###   ########.fr       */
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

void	find_index(t_stack *arr, int *c)
{
	int	i;
	int	j;
	int	*new;

	j = 0;
	new = malloc(sizeof(int) * arr->size_a);
	if (!new)
		free_exit(arr, c, "", 1);
	while (j < arr->size_a)
	{
		i = 0;
		while (arr->a[j] != c[i])
			i++;
		new[j] = i;
		j++;
	}
	j = arr->size_a;
	while (j--)
		arr->a[j] = new[j];
	free(new);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
