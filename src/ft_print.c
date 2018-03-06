/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 19:12:29 by hlely             #+#    #+#             */
/*   Updated: 2017/12/02 17:08:55 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			ft_print_inter(t_list *tmp, int flag[])
{
	ft_putstr((tmp->content)->mode);
	ft_putchar(' ');
	ft_put_relative_space(tmp->content->nlink, 4);
	ft_putnbr(tmp->content->nlink);
	ft_putchar(' ');
	if (!flag[7])
	{
		ft_putstr((tmp->content)->login);
		ft_putstr("  ");
	}
	ft_putstr((tmp->content)->group);
	ft_putstr("  ");
	ft_put_relative_space(tmp->content->size, 6);
	ft_putnbr(tmp->content->size);
	ft_putchar(' ');
	ft_putstr((tmp->content)->time);
	ft_putchar(' ');
}

void				ft_print_l_hidden_solo(t_list *tmp, int flag[])
{
	ft_print_inter(tmp, flag);
	if (tmp->content->type == 4)
	{
		if (tmp->content->path && ft_strcmp(tmp->content->path, "."))
			ft_putcolor(tmp->content->path, LIGHT_CYAN);
		ft_putcolor(tmp->content->name, LIGHT_CYAN);
	}
	else if (tmp->content->type == 10)
	{
		if (tmp->content->path && ft_strcmp(tmp->content->path, "."))
			ft_putcolor(tmp->content->path, MAGENTA);
		ft_putcolor((tmp->content)->name, MAGENTA);
	}
	else
	{
		if (tmp->content->path && ft_strcmp(tmp->content->path, "."))
			ft_putstr(tmp->content->path);
		ft_putstr((tmp->content)->name);
	}
	if (tmp->content->type == 10)
	{
		ft_putstr(" -> ");
		ft_putstr(tmp->content->link);
	}
}

void				ft_print_l_solo(t_list *tmp, int flag[])
{
	ft_print_inter(tmp, flag);
	if (tmp->content->type == 4)
	{
		if (tmp->content->path && ft_strcmp(tmp->content->path, "."))
			ft_putcolor(tmp->content->path, LIGHT_CYAN);
		ft_putcolor(tmp->content->name, LIGHT_CYAN);
	}
	else if (tmp->content->type == 10)
	{
		if (tmp->content->path && ft_strcmp(tmp->content->path, "."))
			ft_putcolor(tmp->content->path, MAGENTA);
		ft_putcolor((tmp->content)->name, MAGENTA);
	}
	else
	{
		if (tmp->content->path && ft_strcmp(tmp->content->path, "."))
			ft_putstr(tmp->content->path);
		ft_putstr((tmp->content)->name);
	}
	if (tmp->content->type == 10)
	{
		ft_putstr(" -> ");
		ft_putstr(tmp->content->link);
	}
}

void				ft_print_solo(t_list *list, int flag[])
{
	if (!flag[3] && list->content->name[0] == '.')
		return ;
	else
	{
		if (list->content->type == 4)
		{
			if (list->content->path && ft_strcmp(list->content->path, "."))
				ft_putcolor(list->content->path, LIGHT_CYAN);
			ft_putcolor(list->content->name, LIGHT_CYAN);
		}
		else if (list->content->type == 10)
		{
			if (list->content->path && ft_strcmp(list->content->path, "."))
				ft_putstr(list->content->path);
			ft_putstr((list->content)->name);
		}
		else
		{
			if (list->content->path && ft_strcmp(list->content->path, "."))
				ft_putstr(list->content->path);
			ft_putstr((list->content)->name);
		}
		if (flag[9] && list->next)
			ft_putchar('\n');
	}
}
