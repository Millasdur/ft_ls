/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 11:24:33 by hlely             #+#    #+#             */
/*   Updated: 2017/12/03 18:24:49 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_clear(t_list **begin_list)
{
	t_list	*destroy;

	while (*begin_list != NULL)
	{
		destroy = *begin_list;
		*begin_list = (*begin_list)->next;
		free(destroy->content->name);
		free(destroy->content->time);
		free(destroy->content->mode);
		free(destroy->content->login);
		free(destroy->content->group);
		if (destroy->content->link)
			free(destroy->content->link);
		if (destroy->content->path)
			free(destroy->content->path);
		free(destroy->content);
		free(destroy);
	}
}
