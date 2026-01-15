/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 03:00:33 by papilaz           #+#    #+#             */
/*   Updated: 2026/01/15 23:14:15 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HEADER_H
# define HEADER_H

# include <string.h>
# include <unistd.h>
# include "get_next_line/get_next_line_bonus.h"
# include "get_next_line/get_next_line_bonus.h"

typedef struct s_list
{
	void			*content; /*content and devices*/
	char			*title_home;
	char			*title_config;
	char			*type;
	int			line;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew_entity(void *content, char *title_home, char *title_config, char *type);
size_t				ft_strlcat(char *dest, char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstnew(void *content);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
int				ft_lstsize(t_list *lst);

t_list	*ft_create_entity_brut(t_list *board, char *name_board, char *name_config);

char	*ft_create_entity(t_list *config, t_list *board, char *name_config, char *name_board);

#endif