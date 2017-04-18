# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atoupart <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 10:08:38 by atoupart          #+#    #+#              #
#    Updated: 2017/03/09 18:29:58 by hchaucha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CC		= gcc -g
RM		= /bin/rm -rf

SRCS	= ft_atoi.c\
		ft_atoi_b.c\
		ft_atoi_base.c\
		ft_pow.c\
		ft_bzero.c\
		ft_bzero_tab.c\
		ft_size_number.c\
		ft_ishexa.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isspace.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isnumber.c\
		ft_isprint.c\
		ft_memccpy.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memdup.c\
		ft_memset.c\
		ft_putchar.c\
		ft_putnbr.c\
		ft_putlnbr.c\
		ft_putstr.c\
		ft_strcat.c\
		ft_strncat.c\
		ft_strchr.c\
		ft_strcmp.c\
		ft_strcpy.c\
		ft_strdup.c\
		ft_strdup_f.c\
		ft_strlcat.c\
		ft_strlen.c\
		ft_strncmp.c\
		ft_strncpy.c\
		ft_ltoa.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strstr.c\
		ft_strrstr.c\
		ft_stroccu.c\
		ft_tolower.c\
		ft_strtolower.c\
		ft_strtoupper.c\
		ft_toupper.c\
		ft_memalloc.c\
		ft_putendl.c\
		ft_strequ.c\
		ft_strnequ.c\
		ft_memdel.c\
		ft_strnew.c\
		ft_strdel.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strsub.c\
		ft_strsub_f.c\
		ft_strclr.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strjoin.c\
		ft_strjoin_f.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_putlnbr.c\
		ft_strtrim.c\
		ft_itoa.c\
		ft_itoa_base.c\
		ft_uitoa_base.c\
		ft_strsplit.c\
		ft_lstnew.c\
		ft_lstadd.c\
		ft_lstdel.c\
		ft_lstdelone.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_lstfree.c\
		ft_lstpushback.c\
		get_next_line.c\
		ft_error.c\
		ft_strndup.c\
		ft_strjoinfree.c\
		ft_strintercal.c\
		ft_delchar.c\
		ft_delchar_f.c\
		ft_straddnchar.c\
		ft_addhexachar.c


FILES	= ft_printf.c\
		split_fmt.c\
		parse_fmt.c\
		conv_funcs.c\
		conv_funcs2.c\
		padding.c\
		padding2.c\
		transform.c\
		transform2.c



CFLAGS	= -Wall -Wextra -Werror

INC		= ./

INC_PRINTF = ./ft_printf/inc/

OBJ		= ${SRCS:%.c=.obj/%.o}


OBJ_PRINTF = ${FILES:%.c=./ft_printf/.obj/%.o}

all: $(NAME)

$(NAME): $(OBJ_PRINTF) $(OBJ)
		@echo ""
		@ar rc $(NAME) $(OBJ_PRINTF) $(OBJ)
		@ranlib $(NAME)
		@echo "création de $(NAME)"

.obj/%.o: %.c
	@mkdir -p .obj
	@$(CC) $(CFLAGS) -c $< -o $@  -I $(INC)
	@printf .

./ft_printf/.obj/%.o: ./ft_printf/src/%.c
	@mkdir -p ./ft_printf/.obj
	@$(CC) $(CFLAGS) -c $< -o $@  -I $(INC_PRINTF)
	@printf .

clean:
		@$(RM) .obj
		@$(RM) ./ft_printf/.obj

fclean: clean
		@$(RM) $(NAME)


re: fclean all

.PHONY: all clean fclean re
