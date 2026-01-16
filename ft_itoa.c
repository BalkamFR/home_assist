/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:26:44 by papilaz           #+#    #+#             */
/*   Updated: 2026/01/16 02:06:41 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	ft_compt_all_number(long n)
{
	int	compt;

	compt = 1;
	if (n < 0)
	{
		n = n * -1;
		compt++;
	}
	while (n >= 10)
	{
		n = n / 10;
		compt++;
	}
	return (compt);
}

static void	ft_putnbr_add_data(long nb, char *tab)
{
	*tab = ((nb % 10) + '0');
	if (nb >= 10)
		ft_putnbr_add_data(nb / 10, tab - 1);
}

char	*ft_itoa(int n)
{
	char	*res;
	long	len;
	long	nb;

	nb = n;
	len = ft_compt_all_number(n);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (nb < 0)
	{
		res[0] = '-';
		nb = nb * -1;
		ft_putnbr_add_data(nb, res + len - 1);
	}
	else
		ft_putnbr_add_data(nb, res + len - 1);
	return (res);
}
