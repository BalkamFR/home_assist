/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 10:34:31 by papilaz           #+#    #+#             */
/*   Updated: 2025/11/23 18:45:35 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && n > i)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	a;
	size_t	len_tab;

	i = 0;
	len_tab = 0;
	if (!big && len == 0)
		return (NULL);
	while (little[len_tab])
		len_tab++;
	if (len_tab == 0)
		return ((char *)big);
	while (big[i] && i < len)
	{
		a = 0;
		while (big[i + a] == little[a] && (i + a) < len && little[a])
			a++;
		if (a == len_tab)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	a;

	a = 0;
	i = 0;
	while (s[i])
	{
		if ((unsigned char)c == s[i])
			a++;
		i++;
	}
	i = 0;
	while (*s)
	{
		if ((unsigned char)c == *s)
			i++;
		if (a == i && (unsigned char)c == *s)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == *s)
		return ((char *)s);
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((unsigned char)c == *s)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == *s)
		return ((char *)s);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	res;
	int	i;

	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] && ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == ' ')))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9' && nptr[i])
	{
		res = res * 10;
		res = (nptr[i] - '0') + res;
		i++;
	}
	return (res * sign);
}
