/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort_t.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 11:34:21 by hlely             #+#    #+#             */
/*   Updated: 2017/11/29 12:13:21 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_swap_data(t_list *curr, t_list *next)
{
	t_dir	*temp;

	temp = curr->content;
	curr->content = next->content;
	next->content = temp;
}

void		ft_list_sort_t(t_list **begin_list)
{
	t_list	*curr;
	t_list	*next;
	int		length;
	int		i;

	i = 0;
	length = ft_list_size(*begin_list);
	while (i < length)
	{
		curr = *begin_list;
		next = curr->next;
		while (next != NULL)
		{
			if (curr->content->etime < next->content->etime)
				ft_swap_data(curr, next);
			curr = next;
			next = curr->next;
		}
		i++;
	}
}
