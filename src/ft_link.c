/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 13:37:30 by hlely             #+#    #+#             */
/*   Updated: 2017/12/04 11:38:27 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_set_name_path(char **name, char **path)
{
	if ((*name = ft_strrchr(*path, '/')) == NULL)
	{
		*name = ft_strdup(*path);
		*path = ft_strdup(".");
	}
	else
	{
		*name = ft_strdup(*name + 1);
		*path = ft_strsub(*path, 0, ft_strlen(*path) - ft_strlen(*name));
	}
}

t_dir	*ft_new_link(t_dirent *dirent, char *path)
{
	t_dir		*result;
	t_stat		*buf;
	char		*name;

	if (!(result = (t_dir*)malloc(sizeof(t_dir))))
		return (NULL);
	if (!(buf = (t_stat*)malloc(sizeof(t_stat))))
		return (NULL);
	path = ft_strjoin(path, "/");
	name = ft_strjoin(path, dirent->d_name);
	result->link = NULL;
	if (lstat(dirent->d_name, buf) == -1)
		return (NULL);
	result->link = ft_strnew(99);
	readlink(name, result->link, 99);
	ft_set_struct(result, dirent, buf);
	free(buf);
	free(path);
	free(name);
	return (result);
}

int		ft_link(char *link, t_list **new)
{
	DIR			*dir;
	t_dirent	*dirent;
	char		*name;

	ft_set_name_path(&name, &link);
	dir = opendir(link);
	while ((dirent = readdir(dir)))
	{
		if (!ft_strcmp(dirent->d_name, name) && dirent->d_type == 10)
		{
			*new = ft_lstnew(ft_new_link(dirent, link), sizeof(t_dir));
			ft_free(dir, name, link);
			return (1);
		}
	}
	ft_free(dir, name, link);
	return (0);
}
