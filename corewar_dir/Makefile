# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hchaucha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/29 10:16:34 by hchaucha          #+#    #+#              #
#    Updated: 2017/02/23 16:37:13 by hchaucha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./src/
SRC_NAME =\
			main.c\
			go_corewar.c\
			make_process.c\
			display.c\
			dump_memory.c\
			parse.c\
			instrs.c\
			instr2.c\
			instr3.c\
			instr4.c\
			instr5.c\
			instr6.c\
			options.c\
			param.c\
			utils_options.c\
			champlst.c\
			memory.c\
			read_file.c\
			descript_ocp.c\
			free_things.c

			

OBJ_PATH = ./obj/
OBJ_NAME = $(SRC_NAME:.c=.o)

INC_PATH = ./inc/
INC_NAME = corewar.h

LIB_PATH = ../libft/

LIB_NAME = -lft

INC_LIB_PATH = ../libft/


# **************************************************************************** #

NAME = corewar
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
		@echo "Compilation de la VM [${GREEN}OK${NC}]"
		@$(CC) $(CFLAGS) $(LIB) -lncurses -lft -o $(NAME) $(OBJ) -g
		@mv corewar ..

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
	@rm -f ../$(NAME)
	@make -C $(LIB_PATH) fclean
	@echo "Suppression de l'VM [${GREEN}OK${NC}]"

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
