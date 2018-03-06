/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 20:28:51 by hlely             #+#    #+#             */
/*   Updated: 2017/12/04 11:43:39 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static DIR	*ft_get_name(char **path, char **name)
{
	DIR *directory;

	ft_strdel(name);
	*name = ft_strdup(*path);
	directory = opendir(".");
	ft_strclr(*path);
	*path = ft_strcpy(*path, ".");
	return (directory);
}

static void	ft_get_name_path(char **name, char **path)
{
	*name = ft_strsub(*name, 1, ft_strlen(*name) - 1);
	*path = ft_strsubdel(*path, 0, ft_strlen(*path) - ft_strlen(*name));
}

void		ft_free(DIR *directory, char *name, char *path)
{
	if (name)
		free(name);
	if (path)
		free(path);
	if (directory)
		closedir(directory);
}

int			ft_check_again(char *av, t_list **list, t_list **new, int flag[])
{
	DIR		*directory;
	char	*name;
	char	*path;

	path = ft_strdup(av);
	name = path;
	if ((name = ft_strrchr(path, '/')) == 0)
		directory = ft_get_name(&path, &name);
	else
	{
		ft_get_name_path(&name, &path);
		if (!(directory = opendir(path)))
			return (0);
	}
	*list = ft_get_info(directory, path, flag);
	if (!ft_search_file(*list, name, path, new))
		return (ft_error_one(path, name));
	ft_free(directory, name, path);
	return (0);
}

int			ft_check_file(char *av, t_list **list, t_list **new, int flag[])
{
	DIR		*directory;
	char	*name;
	char	*path;

	path = ft_strdup(av);
	name = path;
	if ((directory = opendir(path)))
	{
		closedir(directory);
		if (flag[0] && ft_link(path, new))
		{
			free(path);
			return (0);
		}
		free(path);
		return (1);
	}
	else
	{
		free(path);
		return (ft_check_again(av, list, new, flag));
	}
}
