/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:57:23 by papilaz           #+#    #+#             */
/*   Updated: 2026/01/15 21:50:08 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s)
{
	int	c;

	c = '\n';
	if (!s)
		return (0);
	while (*s)
	{
		if ((unsigned char)c == *s)
			return ((char *)s);
		s++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tab;
	int		i;
	int		a;
	int		len1;
	int		len2;

	i = 0;
	a = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	tab = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!tab)
	{
		free(s1);
		return (NULL);
	}
	while (i < len1)
		tab[i++] = s1[a++];
	a = 0;
	while (i < (len1 + len2))
		tab[i++] = s2[a++];
	tab[i] = '\0';
	free(s1);
	return (tab);
}
