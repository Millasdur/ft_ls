/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 14:51:44 by hlely             #+#    #+#             */
/*   Updated: 2017/12/02 17:32:24 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_put_relative_space(int nb, int space)
{
	int i;

	i = 0;
	while (i + ft_nbdigit(nb, 10) < space)
	{
		ft_putchar(' ');
		i++;
	}
}

int		ft_get_longest_name(t_list *list)
{
	size_t	i;

	i = 0;
	while (list)
	{
		if (ft_strlen(list->content->name) > i)
			i = ft_strlen(list->content->name);
		list = list->next;
	}
	return (i);
}

void	ft_putstr_relative(t_list *list, int flag[], size_t space)
{
	size_t	i;

	i = 0;
	ft_print_solo(list, flag);
	if (!flag[3] && list->content->name[0] == '.')
		return ;
	while (i + ft_strlen(list->content->name) < space - 1)
	{
		ft_putchar(' ');
		i++;
	}
}

void	ft_print_col(t_list *list, int flag[])
{
	int row;
	int i;
	int space;

	i = 0;
	space = ft_get_longest_name(list) + 2;
	row = ft_list_size(list) % 4 == 0 ?
		ft_list_size(list) / 4 : ft_list_size(list) / 4 + 1;
	while (i < row)
	{
		if (ft_list_at(list, i))
			ft_putstr_relative(ft_list_at(list, i), flag, space);
		if (ft_list_at(list, i + row))
			ft_putstr_relative(ft_list_at(list, i + row), flag, space);
		if (ft_list_at(list, i + row * 2))
			ft_putstr_relative(ft_list_at(list, i + row * 2), flag, space);
		if (ft_list_at(list, i + row * 3))
			ft_print_solo(ft_list_at(list, i + row * 3), flag);
		if (i != row - 1)
			ft_putchar('\n');
		i++;
	}
}
