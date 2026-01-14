/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:13:38 by papilaz           #+#    #+#             */
/*   Updated: 2025/11/23 18:38:21 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_comptword(char const *tab, char sep, int flag)
{
	int	i;
	int	compt;
	int	compt_all_size;

	compt_all_size = 0;
	i = 0;
	compt = 0;
	while (tab[i])
	{
		while (tab[i] && tab[i] == sep)
			i++;
		if (tab[i] != sep && tab[i])
		{
			compt++;
			while (tab[i] && tab[i] != sep)
			{
				if (flag == compt)
					compt_all_size++;
				i++;
			}
		}
	}
	if (flag == -1)
		return (compt);
	return (compt_all_size);
}

static void	ft_add_data(char const *s, char c, char **tab)
{
	int	a;
	int	b;
	int	i;

	i = 0;
	a = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			b = 0;
			while (s[i] != c && s[i])
			{
				tab[a][b] = s[i];
				i++;
				b++;
			}
			tab[a][b] = '\0';
			a++;
		}
	}
	tab[a] = NULL;
}

static void	ft_allfree(char **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**tab;

	if (!s)
		return (NULL);
	i = 0;
	tab = malloc(sizeof(char *) * (ft_comptword(s, c, -1) + 1));
	if (!tab)
		return (NULL);
	while (i < ft_comptword(s, c, -1))
	{
		tab[i] = malloc(sizeof(char) * (ft_comptword(s, c, i + 1) + 1));
		if (!tab[i])
		{
			ft_allfree(tab, i);
			return (NULL);
		}
		i++;
	}
	ft_add_data(s, c, tab);
	return (tab);
}
