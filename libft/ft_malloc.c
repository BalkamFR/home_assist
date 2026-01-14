/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:56:57 by papilaz           #+#    #+#             */
/*   Updated: 2025/11/10 16:21:10 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (n > i)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tab;

	if (size == 0)
	{
		tab = malloc(0);
		if (!tab)
			return (NULL);
		return (tab);
	}
	if (nmemb <= __SIZE_MAX__ / size)
	{
		tab = malloc(nmemb * size);
		if (!tab)
			return (NULL);
		ft_bzero(tab, nmemb * size);
		return (tab);
	}
	return (NULL);
}

char	*ft_strdup(const char *source)
{
	char	*tab;
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (source[len])
		len++;
	tab = malloc(sizeof(char) * (len + 1));
	if (!tab)
		return (NULL);
	while (source[i])
	{
		tab[i] = source[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
