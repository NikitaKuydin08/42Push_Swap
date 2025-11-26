/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nkuydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 18:07:54 by nkuydin           #+#    #+#             */
/*   Updated: 2025/11/26 15:17:37 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_exit(t_stack *arr, int *c, char *msg, int ex)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	if (arr)
	{
		if (arr->a)
			free(arr->a);
		if (arr->b)
			free(arr->b);
		free(arr);
	}
	if (c)
		free(c);
	exit(ex);
}

void	validate_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc == 1)
		exit(1);
	while (i < argc)
	{
		j = 0;
		if (!(argv[i][0]) || (argv[i][0] && argv[i][0] == '\0'))
			free_exit(NULL, NULL, "Error\n", 1);
		while (argv[i][j])
		{
			if ((!ft_isdigit(argv[i][j]) && argv[i][j] != ' '
			&& argv[i][j] != '+' && argv[i][j] != '-')
			|| (argv[i][j] == '+' && !ft_isdigit(argv[i][j + 1]))
			|| (argv[i][j] == '-' && !ft_isdigit(argv[i][j + 1]))
			|| (ft_isdigit(argv[i][j]) && argv[i][j + 1] == '+')
			|| (ft_isdigit(argv[i][j]) && argv[i][j + 1] == '-')
			|| (argv[i][j] == ' ' && argv[i][j + 1] == '\0'))
				free_exit(NULL, NULL, "Error\n", 1);
			j++;
		}
		i++;
	}
}

int	is_sorted(t_stack *arr)
{
	int	i;

	i = 0;
	while (i < arr->size_a - 1)
	{
		if (arr->a[i] > arr->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	exit_if_sorted_or_has_duplicate(t_stack *arr, int *c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < arr->size_a)
	{
		j = i + 1;
		while (j < arr->size_a)
		{
			if (arr->a[i] == arr->a[j])
				free_exit(arr, c, "Error\n", 1);
			j++;
		}
		i++;
	}
	if (is_sorted(arr))
		free_exit(arr, c, "", 1);
}
