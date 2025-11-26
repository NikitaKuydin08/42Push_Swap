/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nkuydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:14:25 by nkuydin           #+#    #+#             */
/*   Updated: 2025/11/26 15:13:05 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// parsing, I will need to solve the problem with taking multiple
// number of arguments, convert them to integers, and save it inside of arr->a
// Furthermore, I would need to take the string, divide it by spaces, convert
// to integers, abd then somehow store it inside of the arr->a, skiping spaces
// maybe through loop

#include "../includes/push_swap.h"

int		ps_atol(char *str, long long *out);
void	free_temp(t_stack *arr, char **temp, int *c);

void	parse_args(int argc, char **argv, t_stack *arr, int *c)
{
	char		**temp;
	char		*joined;
	int			j;
	int			i;
	long long	value;

	j = 0;
	i = 0;
	joined = join_args(argc, argv);
	if (!joined)
		free_exit(arr, c, "Error\n", 1);
	temp = ft_split(joined, ' ');
	free(joined);
	if (!temp)
		free_exit(arr, c, "Error\n", 1);
	while (temp[i])
	{
		if (!ps_atol(temp[i], &value))
			free_temp(arr, temp, c);
		c[j] = (int)value;
		arr->a[j] = (int)value;
		j++;
		i++;
	}
	free_split(temp);
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
		temp = joined;
		joined = ft_strjoin(temp, argv[i]);
		if (!joined)
			return (free(temp), NULL);
		free(temp);
		if (i != argc - 1)
		{
			temp = joined;
			joined = ft_strjoin(temp, " ");
			if (!joined)
				return (free(temp), NULL);
			free(temp);
		}
		i++;
	}
	return (joined);
}

int	ps_atol(char *str, long long *out)
{
	int			i;
	int			sign;
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
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	result *= sign;
	if (result > INT_MAX || result < INT_MIN)
		return (0);
	*out = result;
	return (1);
}

void	free_temp(t_stack *arr, char **temp, int *c)
{
	free_split(temp);
	free_exit(arr, c, "Error\n", 1);
}
