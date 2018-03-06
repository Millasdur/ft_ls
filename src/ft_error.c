/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 16:22:47 by hlely             #+#    #+#             */
/*   Updated: 2017/12/03 16:23:23 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_error_one(char *path, char *name)
{
	ft_putstr("ls: ");
	if (ft_strcmp(path, "."))
		ft_putstr(path);
	ft_putstr(name);
	ft_putstr(": No such file or directory\n");
	return (1);
}
