/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nkuydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:36:29 by nkuydin           #+#    #+#             */
/*   Updated: 2025/11/26 14:37:27 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		s1_len;
	int		s2_len;
	char	*tab;

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	tab = ft_calloc(s1_len + s2_len + 1, sizeof(char));
	if (!tab)
		return (NULL);
	while (s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	while (*s2)
		tab[i++] = *s2++;
	tab[i] = '\0';
	return (tab);
}
