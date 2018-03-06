/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 11:30:28 by hlely             #+#    #+#             */
/*   Updated: 2017/12/04 11:44:21 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_get_path(int ac, char **av)
{
	int i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] != '-' || (av[i][0] == '-' && !av[i][1]))
			return (i);
		i++;
	}
	return (0);
}

static int	ft_check_dir(char *path, int flag[])
{
	DIR			*directory;
	t_dirent	*dirent;
	char		*name;

	if (!(directory = opendir(path)))
		return (0);
	ft_set_name_path(&name, &path);
	closedir(directory);
	directory = opendir(path);
	while ((dirent = readdir(directory)))
	{
		if (flag[0] && !ft_strcmp(dirent->d_name, name) && dirent->d_type == 10)
		{
			ft_free(directory, name, path);
			return (0);
		}
	}
	ft_free(directory, name, path);
	return (1);
}

static void	ft_get_dir(int ac, char **av, int k, int flag[])
{
	t_list	*list;

	list = NULL;
	while (k < ac)
	{
		if (ft_check_dir(av[k], flag))
		{
			if (k > 2)
				ft_putchar('\n');
			flag[5] = 1;
			if (!ft_strcmp(av[k], "./") && flag[1])
				ft_ls_rec(".", flag);
			else if (flag[1])
				ft_ls_rec(av[k], flag);
			else
				list = ft_ls(av[k], flag);
			ft_list_clear(&list);
		}
		k++;
	}
}

static void	ft_check_argv(int ac, char **av, int k, int flag[])
{
	t_list	*new;
	t_list	*begin;
	t_list	*list;

	flag[5] = 0;
	begin = NULL;
	new = NULL;
	list = NULL;
	while (k < ac)
	{
		if (!ft_check_file(av[k], &list, &new, flag))
		{
			ft_lstaddlast(&begin, new);
			ft_list_clear(&list);
		}
		k++;
	}
	if (new)
	{
		ft_sort_rt(&begin, flag);
		ft_ls_redir(begin, flag);
	}
	ft_list_clear(&begin);
	k = ft_get_path(ac, av);
	ft_get_dir(ac, av, k, flag);
}

int			main(int ac, char **av)
{
	int		flag[10];
	int		k;
	t_list	*list;
	char	*path;

	list = NULL;
	k = ft_get_path(ac, av);
	if (!ft_flag(ac, av, flag))
		return (0);
	if (k == 0)
	{
		path = ft_strnew(1);
		path = ft_strcpy(path, ".");
		flag[5] = 1;
		if (flag[1])
			ft_ls_rec(path, flag);
		else
			list = ft_ls(path, flag);
		ft_strdel(&path);
	}
	else
		ft_check_argv(ac, av, k, flag);
	ft_list_clear(&list);
	return (0);
}
