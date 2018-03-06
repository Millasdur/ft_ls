/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getinfo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 16:00:44 by hlely             #+#    #+#             */
/*   Updated: 2017/12/04 12:07:32 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_free_th(t_stat *buf, char *name, char *path)
{
	free(buf);
	free(path);
	free(name);
}

static int		ft_malloc_struct(t_dir **result, t_stat **buf)
{
	if (!(*result = (t_dir*)malloc(sizeof(t_dir))))
		return (0);
	if (!(*buf = (t_stat*)malloc(sizeof(t_stat))))
		return (0);
	return (1);
}

void			ft_set_struct(t_dir *result, t_dirent *dirent, t_stat *buf)
{
	result->path = NULL;
	result->login = NULL;
	result->group = NULL;
	result->name = ft_strdup(dirent->d_name);
	result->type = dirent->d_type;
	if (buf->st_mtime > time(NULL) || time(NULL) - buf->st_mtime > 15778800)
		result->time = ft_strjoinddel(ft_strsub(ctime(&buf->st_mtime), 4, 7),
				ft_strsub(ctime(&buf->st_mtime), 19, 5));
	else
		result->time = ft_strsub(ctime(&buf->st_mtime), 4, 12);
	result->etime = buf->st_mtime;
	result->mode = ft_get_mode(buf->st_mode, dirent->d_type);
	if (getpwuid(buf->st_uid))
		result->login = ft_strdup(getpwuid(buf->st_uid)->pw_name);
	if (getgrgid(buf->st_gid))
		result->group = ft_strdup(getgrgid(buf->st_gid)->gr_name);
	result->size = buf->st_size;
	result->nlink = buf->st_nlink;
	result->block = buf->st_blocks;
}

static t_dir	*ft_new_one(t_dirent *dirent, char *path)
{
	t_dir		*result;
	t_stat		*buf;
	char		*name;

	if (!(ft_malloc_struct(&result, &buf)))
		return (NULL);
	path = ft_strjoin(path, "/");
	name = ft_strjoin(path, dirent->d_name);
	result->link = NULL;
	if (dirent->d_type == 10)
	{
		if (lstat(name, buf) == -1)
			return (NULL);
		result->link = ft_strnew(99);
		readlink(name, result->link, 99);
	}
	else
	{
		if (stat(name, buf) == -1)
			return (NULL);
	}
	ft_set_struct(result, dirent, buf);
	ft_free_th(buf, name, path);
	return (result);
}

t_list			*ft_get_info(DIR *dir, char *path, int flag[])
{
	t_list		*list;
	t_list		*begin;
	t_dirent	*dirent;

	begin = NULL;
	list = NULL;
	while ((dirent = readdir(dir)) != NULL)
	{
		if ((list = ft_lstnew(ft_new_one(dirent, path), sizeof(t_dir))))
			ft_lstaddlast(&begin, list);
	}
	if (!flag[8])
		ft_list_sort(&begin, &ft_strcmp);
	ft_sort_rt(&begin, flag);
	return (begin);
}
