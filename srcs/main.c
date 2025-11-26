/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nkuydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:53:26 by nkuydin           #+#    #+#             */
/*   Updated: 2025/11/26 15:49:53 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

// void	put_results(t_stack *arr)
// {
// 	int	i;

// 	i = 0;
// 	while (i < arr->size_a - 1)
// 	{
// 		printf("%d ", arr->a[i]);
// 		i++;
// 	}
// 	printf("%d", arr->a[i]);
// }

int	main(int argc, char **argv)
{
	t_stack	*arr;
	int		*c;

	validate_args(argc, argv);
	arr = malloc(sizeof(t_stack));
	if (!arr)
		exit(1);
	init_stacks(argc, argv, arr);
	c = malloc(sizeof(int) * arr->size_a);
	if (!c)
		free_exit(arr, NULL, "Error\n", 1);
	parse_args(argc, argv, arr, c);
	exit_if_sorted_or_has_duplicate(arr, c);
	bubble_sort(c, arr->size_a);
	find_index(arr, c);
	if (arr->size_a < 6)
		small_sort(arr);
	else
		radix_sort(arr);
	free_exit(arr, c, "", 0);
	return (0);
}

void	init_stacks(int argc, char **argv, t_stack *arr)
{
	int	i;

	i = 1;
	arr->size_a = 0;
	arr->size_b = 0;
	while (i < argc)
	{
		if (ft_count_words(argv[i], ' '))
			arr->size_a += ft_count_words(argv[i], ' ');
		else
			arr->size_a++;
		i++;
	}
	arr->a = malloc(sizeof(int) * arr->size_a);
	if (!arr->a)
		free_exit(arr, NULL, "Error\n", 1);
	arr->b = malloc(sizeof(int) * arr->size_a);
	if (!arr->b)
		free_exit(arr, NULL, "Error\n", 1);
}
