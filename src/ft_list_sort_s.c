/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 10:25:10 by hlely             #+#    #+#             */
/*   Updated: 2017/11/30 10:31:48 by hlely            ###   ########.fr       */
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

void		ft_list_sort_s(t_list **begin_list)
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
			if (curr->content->size < next->content->size)
				ft_swap_data(curr, next);
			curr = next;
			next = curr->next;
		}
		i++;
	}
}
