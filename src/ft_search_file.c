/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:48:12 by hlely             #+#    #+#             */
/*   Updated: 2017/12/03 14:55:47 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_cpy_struct(t_dir *content, t_list *list)
{
	content->link = NULL;
	content->path = NULL;
	content->size = list->content->size;
	content->nlink = list->content->nlink;
	content->block = list->content->block;
	content->type = list->content->type;
	content->etime = list->content->etime;
	content->name = ft_strdup(list->content->name);
	content->time = ft_strdup(list->content->time);
	content->mode = ft_strdup(list->content->mode);
	content->login = ft_strdup(list->content->login);
	content->group = ft_strdup(list->content->group);
	if (list->content->link)
		content->link = ft_strdup(list->content->link);
	if (list->content->path)
		content->path = ft_strdup(list->content->path);
}

int				ft_search_file(t_list *list, char *name,
		char *spath, t_list **new)
{
	int		i;
	t_dir	*content;

	i = 0;
	if (!(content = (t_dir*)malloc(sizeof(t_dir))))
		return (0);
	while (list)
	{
		if (!ft_strcmp(list->content->name, name))
		{
			ft_cpy_struct(content, list);
			*new = ft_lstnew(content, sizeof(t_dir));
			(*new)->content->path = ft_strdup(spath);
			(*new)->next = NULL;
			i++;
			return (1);
		}
		list = list->next;
	}
	return (0);
}
