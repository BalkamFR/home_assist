/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 21:37:02 by papilaz           #+#    #+#             */
/*   Updated: 2026/01/15 23:12:42 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


int	main(void)
{
	int		fd1;
	int		line_board;
	int		line_config;
	int		fd2;
	char	*line1;
	char	*line2;
	t_list	*config;
	t_list	*board;
	line_config = 0;
	line_board = 0;

	fd1 = open("files/lovelace", O_RDONLY);
	fd2 = open("files/config.yaml", O_RDONLY);
	if (fd1 < 0 || fd2 < 0)
	{
		perror("open");
		return (1);
	}
	line1 = NULL;
	board = NULL;
	config = NULL;
	line2 = NULL;
	while (1)
	{
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
		if (!line1 && !line2)
			break ;
		if (line1)
		{
			ft_lstadd_front(&board, ft_lstnew(line1));
			board->line = line_board;
			line_board++;		
		}
		if (line2)
		{
			ft_lstadd_front(&config, ft_lstnew(line2));
			config->line = line_config;		
			line_config++;
		}
	}
	ft_create_entity(config, board, "HK Cuisine V2", "salon");
	ft_lstclear(&config, free);
	ft_lstclear(&board, free);
	close(fd1);
	close(fd2);
	return (0);
}
