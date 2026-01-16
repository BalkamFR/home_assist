/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 00:27:45 by papilaz           #+#    #+#             */
/*   Updated: 2026/01/16 00:50:46 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

t_list	*ft_create_entity_brut(t_list *board, char *name_board,
		char *name_config)
{
	int		a;
	char	*line;
	t_list	*entity;

	entity = NULL;
	a = 0;
	line = ft_return_line_number(board, a);
	while (line)
	{
		if (ft_strcmp(name_board, line))
		{
			a++;
			while (line)
			{
				line = ft_return_line_number(board, a);
				if (ft_strcmp("\"title\"", line) == 1)
					return (entity);
				if (ft_strcmp("\"entity\"", line) == 1)
					ft_lstadd_front(&entity, ft_lstnew_entity(extract_data(line,
								'"'), name_board, name_config,
							extract_data_type(extract_data(line, '"'), '.')));
				a++;
			}
		}
		line = ft_return_line_number(board, a);
		a++;
	}
	free(line);
	return (entity);
}

void	format_data(t_list *entity_brut, char *name_files)
{

	if (!entity_brut)
		return ;
	write_on_files(name_files, "  - name: ", entity_brut->title_config);
	write_on_files(name_files, "\n  - port: ", entity_brut->port);
	write_on_files(name_files, "\n    filter:\n      include_entities:\n",
		NULL);
	entity_brut = entity_brut->next;
	while (entity_brut)
	{
		write_on_files(name_files, "        - ", entity_brut->content);
		write_on_files(name_files, "\n", NULL);
		printf("        - %s\n", entity_brut->content);
		entity_brut = entity_brut->next;
	}
	write_on_files(name_files, "\n", NULL);
}
char	*ft_create_entity(t_list *config, t_list *board, char *name_config, char *name_board, char *name_files)
{
	t_list	*entity_brut;

	entity_brut = NULL;
	entity_brut = ft_create_entity_brut(board, name_board, name_config);
	format_data(entity_brut, name_files);
	return (NULL);
}
