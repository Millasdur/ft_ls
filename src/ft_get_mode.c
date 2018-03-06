/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 16:00:53 by hlely             #+#    #+#             */
/*   Updated: 2017/12/03 16:05:02 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			ft_get_type(int type)
{
	if (type == 10)
		return ('l');
	if (type & DT_REG)
		return ('-');
	if (type & DT_DIR)
		return ('d');
	if (type & DT_FIFO)
		return ('f');
	if (type & DT_SOCK)
		return ('s');
	if (type & DT_CHR)
		return ('c');
	if (type & DT_BLK)
		return ('b');
	return (0);
}

char			*ft_get_mode(int mode, int type)
{
	char	*tab;

	tab = ft_strnew(10);
	tab[0] = ft_get_type(type);
	tab[1] = (mode & S_IRUSR) ? 'r' : '-';
	tab[2] = (mode & S_IWUSR) ? 'w' : '-';
	tab[4] = (mode & S_IRGRP) ? 'r' : '-';
	tab[5] = (mode & S_IWGRP) ? 'w' : '-';
	tab[7] = (mode & S_IROTH) ? 'r' : '-';
	tab[8] = (mode & S_IWOTH) ? 'w' : '-';
	if (mode & S_IXUSR)
		tab[3] = (mode & S_ISUID) ? 's' : 'x';
	else
		tab[3] = (mode & S_ISUID) ? 'S' : '-';
	if (mode & S_IXGRP)
		tab[6] = (mode & S_ISGID) ? 's' : 'x';
	else
		tab[6] = (mode & S_ISGID) ? 'S' : '-';
	if (mode & S_IXOTH)
		tab[9] = (mode & S_ISVTX) ? 't' : 'x';
	else
		tab[9] = (mode & S_ISVTX) ? 'T' : '-';
	return (tab);
}
