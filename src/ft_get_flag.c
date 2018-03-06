/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 17:19:55 by hlely             #+#    #+#             */
/*   Updated: 2017/12/02 17:43:14 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_error(void)
{
	ft_putstr(ERROR);
	return (0);
}

static int	ft_check_flag(char **av, int tab[], int i, int j)
{
	if (av[i][j] == 'l')
		tab[0] = 1;
	else if (av[i][j] == 'R')
		tab[1] = 1;
	else if (av[i][j] == 'r')
		tab[2] = 1;
	else if (av[i][j] == 'a')
		tab[3] = 1;
	else if (av[i][j] == 't')
		tab[4] = 1;
	else if (av[i][j] == 'S')
		tab[6] = 1;
	else if (av[i][j] == 'g')
		tab[7] = 1;
	else if (av[i][j] == 'f')
		tab[8] = 1;
	else if (av[i][j] == '1')
		tab[9] = 1;
	else
		return (ft_error());
	return (1);
}

static int	ft_set_flag(char **av, int tab[], int i, int j)
{
	while (av[i][j])
	{
		if (!ft_check_flag(av, tab, i, j))
			return (0);
		j++;
	}
	tab[0] = (tab[7] ? 1 : tab[0]);
	tab[3] = (tab[8] ? 1 : tab[3]);
	return (1);
}

int			ft_flag(int ac, char **av, int tab[])
{
	int	i;
	int j;

	i = 0;
	while (i < 10)
	{
		tab[i] = 0;
		i++;
	}
	i = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][0] == '-' && av[i][1])
		{
			j++;
			if (!ft_set_flag(av, tab, i, j))
				return (0);
		}
		else
			return (1);
		i++;
	}
	return (1);
}
