# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlely <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 12:14:34 by hlely             #+#    #+#              #
#    Updated: 2017/12/02 15:32:50 by hlely            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Werror -Wextra
NAME = libft.a
SRCS_PATH = ./
SRCS = ft_list_at.c ft_list_size.c ft_nbdigit.c ft_putnbrcolornl.c ft_putnbrcolor.c ft_match.c ft_putcolor.c ft_putcolornl.c ft_list_clear.c ft_list_reverse.c ft_list_sort.c ft_issort.c ft_atoi.c ft_power.c ft_sqrt.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstaddlast.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c
OBJ = $(SRCS:.c=.o)
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	@echo Compiling libft ...
	@$(CC) $(FLAGS) -c -I libft.h $(SRCS)
	@ar rc $(NAME) $(OBJ)
	@ranlib libft.a
	@echo "\033[22;32mCompilation libft OK\033[0m"

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
