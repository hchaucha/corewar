ASM_PATH = ./asm
WAR_PATH = ./corewar

all:
	@make -C $(ASM_PATH) all
	@make -C $(WAR_PATH) all

asm:
	@make -C $(ASM_PATH) all

corewar: 
	@make -C $(WAR_PATH) all

clean: 
	@make -C $(ASM_PATH) clean
	@make -C $(WAR_PATH) clean

fclean:
	@make -C $(ASM_PATH) fclean
	@make -C $(WAR_PATH) fclean

re:
	@make -C $(ASM_PATH) re
	@make -C $(WAR_PATH) re

tests: all
	@cp ./asm/asm ./tests
	@cp ./corewar/corewar ./tests
	@sh ./tests/ressources/main_test.sh $(OPT)

clean_tests:
	@rm -rf ./tests/sandbox/
	@rm -rf ./tests/ressources/players/*.cor