/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 20:11:55 by papilaz           #+#    #+#             */
/*   Updated: 2025/12/16 22:26:49 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*extract_stack(char *buffer)
{
	int		len;
	int		i;
	char	*res;

	len = 0;
	i = 0;
	if (!buffer || !buffer[0])
		return (NULL);
	while (buffer[len] && buffer[len] != '\n')
		len++;
	if (ft_strchr(buffer))
		len++;
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	len = 0;
	while (buffer[i] && buffer[i] != '\n')
		res[len++] = buffer[i++];
	if (buffer[i] == '\n')
	{
		res[len] = '\n';
		len++;
	}
	res[len] = '\0';
	return (res);
}

static void	clean_stack(char *stack)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!stack)
		return ;
	while (stack[len] && stack[len] != '\n')
		len++;
	if (ft_strchr(stack))
		len++;
	if (len >= ft_strlen(stack))
	{
		stack[0] = '\0';
		return ;
	}
	while (stack[len])
		stack[i++] = stack[len++];
	stack[i] = '\0';
}

static char	*read_stack(int fd, char *line, int byte_read)
{
	static char	buffer_read[BUFFER_FILES][BUFFER_SIZE + 1];

	if (*buffer_read[fd] != '\0')
	{
		line = ft_strjoin(line, buffer_read[fd]);
		if (!line)
			return (*buffer_read[fd] = '\0', NULL);
	}
	while ((ft_strchr(line) == 0 && byte_read > 0))
	{
		byte_read = read(fd, buffer_read[fd], BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(line);
			buffer_read[fd][0] = '\0';
			return (NULL);
		}
		buffer_read[fd][byte_read] = '\0';
		line = ft_strjoin(line, buffer_read[fd]);
		if (!line)
			return (NULL);
	}
	if (ft_strchr(line))
		clean_stack(buffer_read[fd]);
	return (line);
}

char	*get_next_line(int fd)
{
	char	*res;
	char	*line;
	char	*buffer;
	int		byte_read;

	byte_read = 1;
	res = NULL;
	line = NULL;
	if (fd < 0)
		return (NULL);
	buffer = read_stack(fd, line, byte_read);
	if (!buffer)
		return (NULL);
	res = extract_stack(buffer);
	if (!res)
	{
		free(buffer);
		return (NULL);
	}
	free(buffer);
	return (res);
}
