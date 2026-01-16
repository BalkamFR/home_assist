/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste_chainer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:06:31 by papilaz           #+#    #+#             */
/*   Updated: 2026/01/16 02:13:30 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->line = 0;
	new_node->title_config = NULL;
	new_node->type = NULL;
	new_node->title_home = NULL;
	new_node->next = NULL;
	return (new_node);
}

t_list	*ft_lstnew_entity(void *content, char *title_home, char *title_config,
		char *type)
{
	t_list	*new_node;
	char	*nbrconvert;
	static int portnbr = 2000;
	portnbr ++;
	nbrconvert = ft_itoa(portnbr);
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->line = 0;
	new_node->type = type;
	new_node->title_home = title_home;
	new_node->title_config = title_config;
	new_node->port = nbrconvert;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_list	*ft_lstlast(t_list *lst)
{
	int		size;
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = lst;
	size = ft_lstsize(lst);
	while (i < size - 1 && tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !*lst)
	{
		ft_lstadd_front(lst, new);
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*next;

	tmp = *lst;
	while (tmp)
	{
		next = tmp->next;
		del(tmp->content);
		free(tmp);
		tmp = next;
	}
	*lst = NULL;
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		f(tmp->content);
		tmp = tmp->next;
	}
}

t_list	*ft_lstclear_return(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*next;

	tmp = *lst;
	while (tmp)
	{
		next = tmp->next;
		del(tmp->content);
		free(tmp);
		tmp = next;
	}
	*lst = NULL;
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node1;
	void	*temp;
	void	*temp2;

	if (!f || !del)
		return (NULL);
	node1 = NULL;
	while (lst)
	{
		temp = f(lst->content);
		if (!temp)
			return (ft_lstclear_return(&node1, del));
		temp2 = ft_lstnew(temp);
		if (!temp2)
		{
			ft_lstclear(&node1, del);
			free(temp);
			return (NULL);
		}
		ft_lstadd_back(&node1, temp2);
		lst = lst->next;
	}
	return (node1);
}
