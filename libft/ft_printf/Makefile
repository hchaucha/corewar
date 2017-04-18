# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atoupart <atoupart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/11 21:53:46 by atoupart          #+#    #+#              #
#    Updated: 2017/02/11 21:53:48 by atoupart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CC		= gcc -g
RM		= /bin/rm -rf

FILES	= split_fmt.c\
		parse_fmt.c\
		conv_funcs.c\
		conv_funcs2.c\
		ft_printf.c\
		padding.c\
		padding2.c\
		transform.c\
		transform2.c

SRCS		= $(addprefix src/, $(FILES))

CFLAGS	= -Wall -Wextra -Werror

INC		= ./inc/
OBJ		= ${SRCS:src/%.c=.obj/%.o}

all: $(NAME)

$(NAME): $(OBJ)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)

.obj/%.o: src/%.c
	@mkdir -p .obj
	@$(CC) $(CFLAGS) -c $< -o $@  -I $(INC)

clean:
		@$(RM) .obj

fclean: clean
		@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
