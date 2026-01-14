/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:44:28 by papilaz           #+#    #+#             */
/*   Updated: 2025/11/23 18:42:39 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *charset)
{
	size_t	i;

	i = 0;
	while (charset[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*tab;
	int		i;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	tab = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!tab)
		return (NULL);
	while (i < len1)
	{
		tab[i] = *s1;
		s1++;
		i++;
	}
	while (i < (len1 + len2))
	{
		tab[i] = *s2;
		s2++;
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	src_len;

	i = 0;
	j = 0;
	src_len = ft_strlen(src);
	if (size)
	{
		while (dest[i] && i < size)
			i++;
		if (i >= size)
			return (size + src_len);
		while (src[j] && (i + j) < (size - 1))
		{
			dest[i + j] = src[j];
			j++;
		}
		dest[i + j] = '\0';
	}
	return (i + src_len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = 0;
	while (src[src_len])
		src_len++;
	if (size == 0)
		return (src_len);
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
