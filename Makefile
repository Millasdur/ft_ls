# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlely <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/23 13:33:00 by hlely             #+#    #+#              #
#    Updated: 2017/12/04 12:24:29 by hlely            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wformat -Wextra -Werror
SRCS = ft_check_file.c\
	   ft_error.c\
	   ft_get_info.c\
	   ft_get_flag.c\
	   ft_get_mode.c\
	   ft_list_sort_t.c\
	   ft_list_sort_s.c\
	   ft_link.c\
	   ft_ls.c\
	   ft_ls_l.c\
	   ft_ls_rec.c\
	   ft_padding.c\
	   ft_print.c\
	   ft_search_file.c\
	   main.c
SRCSS = $(addprefix src/, $(SRCS))
LIBFT = ./libft/
NAME = ft_ls
OBJ = $(addprefix src/,$(SRCS:.c=.o))
MAKEFLAGS = s

all:  $(NAME)

$(NAME): $(OBJ)
	@echo Checking libft ...
	@$(MAKE) -C $(LIBFT) MAKEFLAGS=s
	@echo Compiling ft_ls ...
	@cd src/; $(CC) -c $(FLAGS) $(SRCS)
	@$(CC) $(OBJ) $(LIBFT)/libft.a -o $(NAME)
	@echo "\033[22;32mCompilation ft_ls OK\033[0m"

clean:
	@rm -rf $(OBJ)
	@echo Cleaned object files

fclean: clean
	@rm -rf $(NAME)
	@echo "Cleaned $(NAME)"

re : fclean all
