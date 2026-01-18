/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 00:31:09 by papilaz           #+#    #+#             */
/*   Updated: 2026/01/18 20:13:46 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	create_new_files(void)
{
	t_list	*config;
	t_list	*board;
	char	*path_config;
	char	*path_board;

	path_config = return_info_file("config_file.json", "config");
	path_board = return_info_file("config_file.json", "home");
	config = reforme_files(path_config);
	board = transforme_files_on_list(path_board);
	remplace_all_files(path_config, config);
	
	write_on_files(path_config, "homekit:\n", NULL);
	ft_parce_and_create_piece(board, board, path_config);
	
	free(path_config);
	free(path_board);
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

void	ft_parce_and_create_piece(t_list *files_config, t_list *files_config2, char *path_file)
{
	char	*new;

	new = NULL;
	while (files_config)
	{
		if (ft_strcmp("\"title\"", files_config->content) == 1
			&& ft_strcmp("debug", files_config->content) == 0
			&& ft_strcmp("Maison Mushroom", files_config->content) == 0
			&& ft_strcmp("Vue Design", files_config->content) == 0)
		{
			new = extract_data(files_config->content, '"');
			ft_create_entity(files_config2, new, path_file);
		}
		files_config = files_config->next;
	}
}
