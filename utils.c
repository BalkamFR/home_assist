/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 02:50:21 by papilaz           #+#    #+#             */
/*   Updated: 2026/01/14 04:27:58 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


int	ft_strcmp(char *name_board, char *board_content)
{
	int	i;
	int	a;
	int	len1;

	len1 = ft_strlen(name_board);
	i = 0;
	a = 0;
	while (board_content[i])
	{
		while (board_content[i] == name_board[a] && board_content[i] && name_board[a])
		{
			i++;
			a++;
		}
		if (a == len1)
			return(1);
		else
			a = 0;
		i++;
	}
	return(0);
}

char	*ft_return_line(t_list *board, char *name_board)
{
	while (board)
	{
		if (ft_strcmp(name_board, board->content))
		{
			return((char *)board->content);
			printf("Ca");
		}
		board = board->next;
	}
	return(NULL);
}

char	*ft_create_entity(t_list *config, t_list *board, char *name_config, char *name_board)
{
	return(ft_return_line(config, name_config));
}

char	*ft_addback(char *source, char *line)
{
	char	*tab;
	size_t	i;
	size_t	a;

	i = 0;
	a = 0;
	
	if (!source)
		return(line);	
	tab = malloc(ft_strlen(source) + ft_strlen(line) + 1);
	if (!tab)
		return (NULL);
	while (source[i])
	{
		tab[i] = source[i];
		i++;
	}
	while (line[i])
		tab[i++] = line[a++];
	tab[i] = '\0';
	free(line);
	return (tab);
}
