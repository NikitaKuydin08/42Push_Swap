/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nkuydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:14:25 by nkuydin           #+#    #+#             */
/*   Updated: 2025/11/02 19:25:19 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// parsing, I will need to solve the problem with taking multiple
// number of arguments, convert them to integers, and save it inside of arr->a
// Furthermore, I would need to take the string, divide it by spaces, convert
// to integers, abd then somehow store it inside of the arr->a, skiping spaces
// maybe through loop

#include "../includes/push_swap.h"

int	ps_atol(char *str, t_stack *arr);

void	parse_args(int argc, char **argv, t_stack *arr)
{
	char	**temp;
	char	*joined;
	int		count;
	int		i;
	int		j;

	i = 0;
	count = 0;
	j = 0;
	joined = join_args(argc, argv);
	temp = ft_split(joined, ' ');
	free(joined);
	while (temp[count])
		count++;
	while (i < count)
	{
		arr->a[j++] = ps_atol(temp[i], arr);
		free(temp[i]);
		i++;
	}
	free(temp);
	exit_if_sorted_or_has_duplicate(arr);
}

char	*join_args(int argc, char **argv)
{
	char	*joined;
	int		i;

	i = 1;
	joined = ft_strdup("");
	while (i < argc)
	{
		joined = ft_strjoin(joined, argv[i]);
		if (i != argc - 1)
			joined = ft_strjoin(joined, " ");
		i++;
	}
	return (joined);
}

int	ps_atol(char *str, t_stack *arr)
{
	int			i;
	long		sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		free_exit(arr, "Error\n");
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	result *= sign;
	if (result > INT_MAX || result < INT_MIN)
		free_exit(arr, "Error\n");
	return (result);
}
