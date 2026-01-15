/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 02:50:21 by papilaz           #+#    #+#             */
/*   Updated: 2026/01/15 23:17:04 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_addback(char *source, char *line)
{
	char	*tab;
	size_t	i;
	size_t	a;

	i = 0;
	a = 0;
	if (!source)
		return (line);
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
		while (board_content[i] == name_board[a] && board_content[i]
			&& name_board[a])
		{
			i++;
			a++;
		}
		if (a == len1)
			return (1);
		else
			a = 0;
		i++;
	}
	return (0);
}

char	*ft_return_line_number(t_list *board, int line)
{
	while (board)
	{
		if (line == board->line)
			return ((char *)board->content);
		board = board->next;
	}
	return (NULL);
}

char	*extract_data(char *brut, char sep)
{
	char	*data_clean;
	int		len;
	int		i;
	int		count;

	len = 0;
	count = 0;
	i = 0;
	while (brut[i])
	{
		if (brut[i] == sep)
			count++;
		if (count == 3 && brut[i] != sep)
			len++;
		i++;
	}
	data_clean = malloc(len + 1);
	if (!data_clean)
		return (NULL);
	i = 0;
	len = 0;
	count = 0;
	while (brut[i])
	{
		if (brut[i] == sep)
			count++;
		if (count == 3 && brut[i] != sep)
			data_clean[len++] = brut[i];
		i++;
	}
	data_clean[len] = '\0';
	return (data_clean);
}

char	*extract_data_type(char *brut, char sep)
{
	char	*data_clean;
	int		len;
	int		i;
	
	len = 0;
	i = 0;
	while (brut[len] != sep)
		len++;
	data_clean = malloc(len + 1);
	if (!data_clean)
		return (NULL);
	while (brut[i] != sep)
	{
		data_clean[i] = brut[i];
		i++;
	}
	data_clean[i] = '\0';
	free(brut);
	return (data_clean);
}

t_list	*ft_create_entity_brut(t_list *board, char *name_board, char *name_config)
{
	int		a;
	char	*line;
	t_list *entity;
	
	entity = NULL;
	a = 0;
	line = ft_return_line_number(board, a);
	while (line)
	{
		if (ft_strcmp(name_board, line))
		{
			printf("%s", line);
			a++;
			while (line)
			{
				line = ft_return_line_number(board, a);
				if (ft_strcmp("\"title\"", line) == 1)
					return (entity);
				if (ft_strcmp("\"entity\"", line) == 1)
					ft_lstadd_front(&entity, ft_lstnew_entity(extract_data(line, '"'), name_board, name_config, extract_data_type(extract_data(line, '"'), '.')));
				a++;
			}
		}
		line = ft_return_line_number(board, a);
		a++;
	}
	free(line);
	return (entity);
}

char	*ft_create_entity(t_list *config, t_list *board, char *name_config, char *name_board)
{
	t_list	*entity_brut;
	
	entity_brut = ft_create_entity_brut(board, name_board, name_config);
	return (NULL);
}


