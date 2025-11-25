/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nkuydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:14:25 by nkuydin           #+#    #+#             */
/*   Updated: 2025/11/25 20:01:41 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// parsing, I will need to solve the problem with taking multiple
// number of arguments, convert them to integers, and save it inside of arr->a
// Furthermore, I would need to take the string, divide it by spaces, convert
// to integers, abd then somehow store it inside of the arr->a, skiping spaces
// maybe through loop

#include "../includes/push_swap.h"

int		ps_atol(char *str, t_stack *arr, char **temp, int *c);
void	free_temp(t_stack *arr, char **temp, int *c);

void	parse_args(int argc, char **argv, t_stack *arr, int *c)
{
	char	**temp;
	char	*joined;
	int		count;
	int		j;
	int		i;

	count = 0;
	j = 0;
	i = 0;
	joined = join_args(argc, argv);
	temp = ft_split(joined, ' ');
	free(joined);
	while (temp[count])
		count++;
	while (i < count)
	{
		c[j] = ps_atol(temp[i], arr, temp, c);
		arr->a[j] = c[j];
		j++;
		i++;
	}
	free_split(temp);
	exit_if_sorted_or_has_duplicate(arr, c);
}

char	*join_args(int argc, char **argv)
{
	char	*joined;
	char	*temp;
	int		i;

	i = 1;
	joined = ft_strdup("");
	while (i < argc)
	{
		temp = ft_strjoin(joined, argv[i]);
		free(joined);
		if (i != argc - 1)
		{
			joined = ft_strjoin(temp, " ");
			free(temp);
		}
		i++;
	}
	return (joined);
}

int	ps_atol(char *str, t_stack *arr, char **temp, int *c)
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
		free_temp(arr, temp, c);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	result *= sign;
	if (result > INT_MAX || result < INT_MIN)
		free_temp(arr, temp, c);
	return (result);
}

void	free_temp(t_stack *arr, char **temp, int *c)
{
	free_split(temp);
	free_exit(arr, c, "Error\n");
}
