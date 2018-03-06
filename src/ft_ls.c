/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:08:08 by hlely             #+#    #+#             */
/*   Updated: 2017/12/04 11:23:35 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_sort_rt(t_list **list, int flag[])
{
	if (!flag[8])
	{
		if (flag[6])
			ft_list_sort_s(list);
		else if (flag[4])
			ft_list_sort_t(list);
		if (flag[2])
			ft_list_reverse(list);
	}
}

void		ft_print_normal(t_list *list, int flag[])
{
	t_list	*begin;

	begin = list;
	if (flag[9])
	{
		while (list)
		{
			ft_print_solo(list, flag);
			list = list->next;
		}
	}
	else
		ft_print_col(list, flag);
	if (begin)
		ft_putchar('\n');
}

t_list		*ft_ls_regular(char *path, int flag[])
{
	t_list	*list;
	t_list	*begin;
	DIR		*dir;

	if (!(dir = opendir(path)))
		return (0);
	list = ft_get_info(dir, path, flag);
	begin = list;
	closedir(dir);
	if (ft_strcmp(path, "."))
	{
		ft_putstr(path);
		ft_putstr(":\n");
	}
	ft_print_normal(list, flag);
	return (begin);
}

t_list		*ft_ls(char *path, int flag[])
{
	if (flag[0])
		return (ft_ls_l(path, flag));
	else
		return (ft_ls_regular(path, flag));
}
