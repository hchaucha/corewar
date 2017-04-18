# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egaborea <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/29 10:16:34 by egaborea          #+#    #+#              #
#    Updated: 2017/02/23 16:37:13 by hchaucha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./src/
SRC_NAME =\
			main.c\
			algo/algo.c\
			algo/stock_file.c\
			algo/utils.c\
			algo/init.c\
			algo/add_to_labellst.c\
			algo/get_nb_label_instr.c\
			algo/print_cor_head.c\
			algo/print_cor_instr.c\
			algo/get_value_param.c\
			algo/create_cor_file.c\
			algo/create_tab_instruction.c\
			algo/get_ocp_index.c\
			algo/get_label_index.c\
			algo/get_hexa.c\
			algo/instructions.c\
			algo/instructions2.c\
			algo/instructions3.c\
			algo/instructions4.c\
			algo/free_things.c\
			parse/parse.c\
			parse/utils.c\
			parse/utils_2.c\
			parse/utils_3.c\
			parse/label.c\
			parse/reg_label.c\
			parse/check_valid_param.c\
			parse/check_operand.c\
			parse/check_name_comment.c\
			parse/check_live_zjmp_lfork.c\
			parse/check_aff.c\
			parse/check_arg.c\
			parse/check_ld_lld.c\
			parse/check_st.c\
			parse/check_add_sub.c\
			parse/check_and_or_xor.c\
			parse/check_ldi.c\
			parse/check_sti.c\
			parse/check_lldi.c\
			parse/match_label.c

OBJ_PATH = ./obj/
OBJ_NAME = $(SRC_NAME:.c=.o)

INC_PATH = ./inc/
INC_NAME = asm.h

LIB_PATH = ../libft/

LIB_NAME = -lft

INC_LIB_PATH = ../libft/


# **************************************************************************** #

NAME = asm
CC = gcc
CFLAGS = -Werror -Wextra -Wall

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
LIB = $(addprefix -L, $(LIB_PATH))
INC = $(addprefix -I, $(INC_PATH))
INC_LIB = $(addprefix -I, $(INC_LIB_PATH))
OBJ_DIRS = $(sort $(dir $(OBJ)))

GREEN = \033[0;32m
NC = \033[0m

all: lib $(NAME)

$(NAME): $(OBJ)
		@echo "Compilation de l'asm [${GREEN}OK${NC}]"
		@$(CC) $(CFLAGS) $(LIB) -lft -o $(NAME) $(OBJ) -g

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	@mkdir -p $(OBJ_DIRS)
	@$(CC) $(CFLAGS) $(INC) $(INC_LIB) -o $@ -c $< -g

lib:
	@make -C $(LIB_PATH) all

clean:
	@rm -f $(OBJ)
	@make -C $(LIB_PATH) clean
	@rmdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_PATH) fclean
	@echo "Suppression de l'asm [${GREEN}OK${NC}]"

re: fclean all

push:
	@git add *
	@git commit -m "Commit By Makefile"
	@git push

norme:
	norminette $(SRC)
	norminette $(INC_PATH)$(INC_NAME)

tests: all
	@cp ./asm ./tests
	@sh ./tests/ressources/asm_tests.sh $(OPT)

clean_tests:
	@rm -rf ./tests/sandbox/
	@rm -rf ./tests/ressources/players/*.cor
