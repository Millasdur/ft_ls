/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 11:10:04 by hlely             #+#    #+#             */
/*   Updated: 2017/12/04 11:37:37 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <unistd.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <sys/xattr.h>
# include <time.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"
# define ERROR "ft_ls: illegal option\nusage: ./ft_ls [-afglrRtS1]\n"

typedef struct dirent	t_dirent;
typedef struct stat		t_stat;
typedef struct passwd	t_passwd;
typedef struct group	t_group;

typedef struct			s_dir
{
	int					size;
	int					nlink;
	int					block;
	int					type;
	long				etime;
	char				*name;
	char				*time;
	char				*mode;
	char				*login;
	char				*group;
	char				*link;
	char				*path;
}						t_dir;

struct s_list			*ft_get_info(DIR *dir, char *path, int flag[]);
struct s_list			*ft_ls(char *path, int flag[]);
struct s_list			*ft_ls_regular(char *path, int flag[]);
struct s_list			*ft_ls_l(char *path, int flag[]);

int						ft_check_file(char *path, struct s_list **list,
		struct s_list **new, int flag[]);
int						ft_flag(int c, char **av, int tab[]);
int						ft_error_one(char *path, char *name);
int						ft_link(char *link, struct s_list **new);
int						ft_search_file(struct s_list *list,
		char *name, char *spath, struct s_list **new_lst);

void					ft_free(DIR *directory, char *name, char *path);
void					ft_ls_rec(char *path, int flag[]);
void					ft_list_sort_t(struct s_list **list);
void					ft_list_sort_s(struct s_list **list);
void					ft_print_normal(struct s_list *list, int flag[]);
void					ft_print_l(struct s_list *list, int flag[]);
void					ft_print_l_hidden(struct s_list *list, int flag[]);
void					ft_print_l_solo(struct s_list *list, int flag[]);
void					ft_print_l_hidden_solo(struct s_list *list,
		int flag[]);
void					ft_print_solo(struct s_list *list,
		int flag[]);
void					ft_put_relative_space(int nb, int space);
void					ft_print_col(struct s_list *list, int flag[]);
void					ft_ls_redir(struct s_list *list, int flag[]);
void					ft_set_name_path(char **name, char **path);
void					ft_set_struct(t_dir *result,
		t_dirent *dirent, t_stat *buf);
void					ft_sort_rt(struct s_list **list, int flag[]);

char					*ft_get_mode(int mode, int type);
#endif
