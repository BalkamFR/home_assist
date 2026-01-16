/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 00:31:09 by papilaz           #+#    #+#             */
/*   Updated: 2026/01/16 01:07:18 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	create_new_files(void)
{
	t_list	*config;
	t_list	*config2;
	t_list	*board;

	config = transforme_files_on_list("files/config.yaml");
	config2 = reforme_files("files/config.yaml");
	board = transforme_files_on_list("files/lovelace");
	remplace_all_files("test.txt", config2);
	ft_create_entity(config, board, "HK Cuisine V2", "Pierre", "test.txt");
	ft_lstclear(&config, free);
	ft_lstclear(&config2, free);
	ft_lstclear(&board, free);
}

t_list	*transforme_files_on_list(char *name_files)
{
	t_list	*list_transform;
	int		fd1;
	int		len;
	char	*line;

	line = NULL;
	list_transform = NULL;
	len = 0;
	fd1 = open(name_files, O_RDONLY);
	if (fd1 < 0)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd1);
		if (!line)
			break ;
		if (line)
		{
			ft_lstadd_front(&list_transform, ft_lstnew(line));
			list_transform->line = len;
			len++;
		}
	}
	close(fd1);
	return (list_transform);
}

t_list	*reforme_files(char *name_files)
{
	t_list	*list_transform;
	int		fd1;
	int		len;
	char	*line;

	line = NULL;
	list_transform = NULL;
	len = 0;
	fd1 = open(name_files, O_RDONLY);
	if (fd1 < 0)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd1);
		if (!line)
			break ;
		if (line)
		{
			ft_lstadd_back(&list_transform, ft_lstnew(line));
			list_transform->line = len;
			len++;
		}
	}
	close(fd1);
	return (list_transform);
}
