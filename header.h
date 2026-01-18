/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 03:00:33 by papilaz           #+#    #+#             */
/*   Updated: 2026/01/18 20:12:45 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "get_next_line/get_next_line_bonus.h"
# include <string.h>
# include <unistd.h>

# ifndef PORT_DEVICES
#  define PORT_DEVICES 2000
# endif

typedef struct s_list
{
	char *content; /*content and devices*/
	char			*title_home;
	char			*title_config;
	char			*type;
	char			*port;
	int				line;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew_entity(void *content, char *title_home,
						char *title_config, char *type);
size_t				ft_strlcat(char *dest, char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstnew(void *content);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
int					ft_lstsize(t_list *lst);

t_list				*ft_create_entity_brut(t_list *board, char *name_board,
						char *name_config);

int					write_on_files(char *name_files, char *text, char *data);
int					remplace_all_files(char *name_files, t_list *old_files);
void				del_all_content_files(char *names_files);
int					ft_strcmp(char *name_board, char *board_content);
char				*extract_data(char *brut, char sep);
char				*extract_data_type(char *brut, char sep);
t_list				*ft_create_entity_brut(t_list *board, char *name_board,
						char *name_config);
void				format_data(t_list *entity_brut, char *name_files);
char				*ft_addback(char *source, char *line);
char				*ft_return_line_number(t_list *board, int line);
char				*ft_create_entity(t_list *board, char *name_board,
						char *name_files);
t_list				*transforme_files_on_list(char *name_files);
void				create_new_files(void);
t_list				*reforme_files(char *name_files);
char				*ft_itoa(int n);
char				*return_info_file(char *file, char *name);
void				ft_lstclear_one(t_list **lst);
void	ft_parce_and_create_piece(t_list *files_config, t_list *files_config2, char *path_file);
						
#endif