/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nkuydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:53:26 by nkuydin           #+#    #+#             */
/*   Updated: 2025/11/13 22:17:11 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*arr;
	int	i;

	i = 0;
	validate_args(argc, argv);
	arr = malloc(sizeof(t_stack));
	if (!arr)
		exit(1);
	init_stacks(argc, argv, arr);
	parse_args(argc, argv, arr);
	if (arr->size_a == 2)
		sa(arr);
	else if (arr->size_a == 3)
		sort_three(arr);
	else if (arr->size_a == 4)
		sort_four(arr);
	else if (arr->size_a == 5)
		sort_five(arr);
	while (i < arr->size_a)
	{
		printf("%i ", arr->a[i]);
		i++;
	}
	exit_if_sorted_or_has_duplicate(arr);
	free_exit(arr, "Error\n");
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
		free_exit(arr, "Error\n");
	arr->b = malloc(sizeof(int) * arr->size_a);
	if (!arr->b)
		free_exit(arr, "Error\n");
}
