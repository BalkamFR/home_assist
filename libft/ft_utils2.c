/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:59:43 by papilaz           #+#    #+#             */
/*   Updated: 2025/11/23 18:30:18 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ischar(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = 0;
	i = 0;
	while (s1[end])
		end++;
	end--;
	while (s1[start] && ft_ischar(set, s1[start]))
		start++;
	while (end >= start && ft_ischar(set, s1[end]))
		end--;
	result = malloc(sizeof(char) * (end - start + 2));
	if (!result)
		return (NULL);
	while (start <= end)
		result[i++] = s1[start++];
	result[i] = '\0';
	return (result);
}
