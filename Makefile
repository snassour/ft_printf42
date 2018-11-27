# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snassour <snassour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/12 11:29:25 by snassour          #+#    #+#              #
#    Updated: 2016/10/15 14:53:33 by snassour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address

SRC_PATH = ./srcs/

OBJ_PATH = ./obj/

SRC_NAME = addconv.c\
flags.c\
flags2.c\
ft_allcaps.c\
ft_atoi.c\
ft_fill.c\
ft_isdigit.c\
ft_lltoa.c\
ft_printf.c\
ft_printf_extend.c\
ft_strchr.c\
ft_strcpy.c\
ft_strdel.c\
ft_strdup.c\
ft_strdup_len.c\
ft_strlen.c\
ft_strnew.c\
ft_strrevcpy.c\
ft_ulltoa.c\
integer.c\
invalid_char_wchar.c\
str_wstr.c\
tools1.c\
unsigned.c\
wchartools.c\
ft_strncpy.c\
ft_init_printf_cv.c

OBJ_NAME = $(SRC_NAME:.c=.o)

INC_PATH = ./includes/\

NAME = libftprintf.a

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME):	$(OBJ)
			ar rc $(NAME) $(OBJ)
			ranlib $(NAME)

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c
				@mkdir -p $(OBJ_PATH)
				@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean: 
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all
