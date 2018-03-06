/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 20:05:49 by hlely             #+#    #+#             */
/*   Updated: 2017/12/04 11:23:49 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_print_total(t_list *list, int flag[])
{
	int nb;

	nb = 0;
	while (list)
	{
		if (!flag[3] && list->content->name[0] == '.')
			list = list->next;
		else
		{
			nb += list->content->block;
			list = list->next;
		}
	}
	ft_putstr("total ");
	ft_putnbr(nb);
	ft_putchar('\n');
}

void			ft_print_l_hidden(t_list *tmp, int flag[])
{
	while (tmp)
	{
		ft_print_l_hidden_solo(tmp, flag);
		ft_putchar('\n');
		tmp = tmp->next;
	}
}

void			ft_print_l(t_list *tmp, int flag[])
{
	while (tmp)
	{
		if (tmp->content->name[0] != '.')
		{
			ft_print_l_solo(tmp, flag);
			ft_putchar('\n');
		}
		tmp = tmp->next;
	}
}

void			ft_ls_redir(t_list *list, int flag[])
{
	if (!flag[0])
		ft_print_normal(list, flag);
	else if (flag[3])
		ft_print_l_hidden(list, flag);
	else
		ft_print_l(list, flag);
	ft_putchar('\n');
}

t_list			*ft_ls_l(char *path, int flag[])
{
	DIR		*dir;
	t_list	*begin_list;
	t_list	*tmp;

	if (ft_strcmp(path, ".") && flag[5])
	{
		ft_putstr(path);
		ft_putstr(":\n");
	}
	if (!(dir = opendir(path)))
		return (0);
	begin_list = ft_get_info(dir, path, flag);
	closedir(dir);
	tmp = begin_list;
	if (ft_list_size(tmp) != 2 || flag[3])
		ft_print_total(tmp, flag);
	if (flag[3])
		ft_print_l_hidden(tmp, flag);
	else
		ft_print_l(tmp, flag);
	return (begin_list);
}
