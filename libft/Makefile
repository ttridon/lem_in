# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttridon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 09:52:44 by ttridon           #+#    #+#              #
#    Updated: 2016/05/25 18:47:58 by ttridon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

CPPFLAGS = -I includes

SRC_NAME = ft_strlen.c				ft_bzero.c				ft_itoa_base.c	\
		   ft_itoa.c				ft_putchar.c			ft_putstr.c		\
		   ft_putnbr.c				ft_puissance.c			ft_toupper.c	\
		   ft_tolower.c				ft_atoi.c				ft_strcpy.c		\
		   ft_strncpy.c				ft_putendl.c			ft_strchr.c		\
		   ft_strjoin.c				ft_isspace.c			ft_strcmp.c		\
		   ft_strncmp.c				ft_strdup.c				ft_strcat.c		\
		   ft_strncat.c				ft_putwchar.c			ft_strtrim.c	\
		   ft_strstr.c				ft_strnstr.c			ft_strrchr.c	\
		   ft_isdigit.c				ft_isascii.c			ft_isalpha.c	\
		   ft_isprint.c				ft_isalnum.c			ft_putchar_fd.c	\
		   ft_putstr_fd.c			ft_putendl_fd.c			ft_putnbr_fd.c	\
		   ft_strnew.c				ft_strdel.c				get_next_line.c	\
		   ft_strndup.c				ft_strequ.c				ft_strnequ.c

SRC_PATH = src/

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ_PATH = obj/

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -f $(SRC:.c=.o)
	rm -rf $(OBJ_PATH) 

fclean: clean
	rm -f $(NAME)

re: fclean all
