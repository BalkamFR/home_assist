/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 00:31:09 by papilaz           #+#    #+#             */
/*   Updated: 2026/01/16 03:39:47 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	create_new_files(void)
{
	t_list	*config;
	t_list	*board;
	char	*files_edit;

	files_edit = "../configuration.yaml";
	config = reforme_files(files_edit);
	board = transforme_files_on_list("../../config/.storage/lovelace");
	remplace_all_files(files_edit, config);
	write_on_files(files_edit, "homekit:\n", NULL);
	ft_create_entity(board, "Cuisine", files_edit);
	ft_create_entity(board, "Salon", files_edit);
	ft_create_entity(board, "Chambre Pierre", files_edit);
	ft_create_entity(board, "Chambre Sacha", files_edit);
	ft_create_entity(board, "Chambre Hanaé", files_edit);
	ft_create_entity(board, "Chambre Chiara", files_edit);
	ft_create_entity(board, "Salles de Bain", files_edit);
	ft_create_entity(board, "Buanderie", files_edit);
	ft_create_entity(board, "Cinéma", files_edit);
	ft_create_entity(board, "Ami 1", files_edit);
	ft_create_entity(board, "Pacome", files_edit);
	ft_create_entity(board, "Divers", files_edit);
	ft_lstclear(&config, free);
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
