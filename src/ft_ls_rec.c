/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_rec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 20:56:31 by hlely             #+#    #+#             */
/*   Updated: 2017/12/03 10:21:09 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_ls_rec_loop(char *path, t_list *cur_dir, int flag[])
{
	char	*tmp;

	tmp = NULL;
	while (cur_dir)
	{
		if (!flag[3] && cur_dir->content->name[0] == '.')
			cur_dir = cur_dir->next;
		else if (cur_dir->content->type == 4 &&
				ft_strcmp(cur_dir->content->name, "..") &&
				ft_strcmp(cur_dir->content->name, "."))
		{
			ft_putchar('\n');
			if (path[ft_strlen(path) - 1] != '/')
				tmp = ft_strjoin(path, "/");
			if (ft_strcmp(path, "/") == 0)
				tmp = ft_strdup(path);
			tmp = ft_strjoindel(tmp, cur_dir->content->name);
			ft_ls_rec(tmp, flag);
			if (tmp)
				free(tmp);
			cur_dir = cur_dir->next;
		}
		else
			cur_dir = cur_dir->next;
	}
}

void			ft_ls_rec(char *path, int flag[])
{
	t_list	*cur_dir;
	t_list	*begin;

	cur_dir = ft_ls(path, flag);
	begin = cur_dir;
	ft_ls_rec_loop(path, cur_dir, flag);
	ft_list_clear(&begin);
}
