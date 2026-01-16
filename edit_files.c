/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 00:24:26 by papilaz           #+#    #+#             */
/*   Updated: 2026/01/16 01:08:26 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	write_on_files(char *name_files, char *text, char *data)
{
	int	fd;

	fd = open(name_files, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		return (-1);
	if (text)
		write(fd, text, ft_strlen(text));
	if (data)
		write(fd, data, ft_strlen(data));
	close(fd);
	return (1);
}

int	remplace_all_files(char *name_files, t_list *old_files)
{
	int	error;
	
	del_all_content_files(name_files);
	error = 0;
	while (old_files)
	{
		if (ft_strcmp("homekit:" , old_files->content) == 1)
			break ;
		error = write_on_files(name_files, old_files->content, NULL);
		if (error == -1)
			return (error);
		old_files = old_files->next;
	}
	return (1);
}

void	del_all_content_files(char *names_files)
{
	truncate(names_files, 0);
}