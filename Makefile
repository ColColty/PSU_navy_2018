##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC_DIR	=	$(realpath ./src)

LIB_FILE	=	$(realpath ./lib/my/)

TEST_SRC	=	$(realpath ./tests)

SRC	=	$(SRC_DIR)/navy.c	\
	$(SRC_DIR)/map.c	\
	$(SRC_DIR)/signal.c	\
	$(SRC_DIR)/transmission.c	\
	$(SRC_DIR)/communication.c	\
	$(SRC_DIR)/gestion_player_defender.c	\
	$(SRC_DIR)/map_tool.c	\
	$(SRC_DIR)/game_loop.c	\
	$(SRC_DIR)/game_condition.c	\
	$(SRC_DIR)/hit_missed.c	\
	$(SRC_DIR)/free.c	\
	$(SRC_DIR)/error_handle.c \
	$(SRC_DIR)/error_handle_2.c	\

TESTS	=	$(TEST_SRC)/main_tests.c	\
	$(TEST_SRC)/transmission_tests.c	\
	$(TEST_SRC)/free_tests.c	\
	$(TEST_SRC)/player_tests.c	\
	$(TEST_SRC)/hit_missed_tests.c	\

NAME	=	navy

MAIN_SRC	=	main.c

LIB	=	-L$(LIB_FILE) -lmy -g3

INCLUDE	=	-I./include

OBJ	=	$(SRC:.c=.o)

DEFAULT	=	\033[0m
GREEN	=	\033[0;32m
RED	=	\033[0;31m

all:	$(NAME)

$(NAME):	$(OBJ)
	@make -C $(LIB_FILE)
	gcc -o $(NAME) $(MAIN_SRC) $(OBJ) $(INCLUDE) $(LIB)

clean:
	@make clean -C $(LIB_FILE)
	@rm -f *.gc*
	@find . -name "*.o" -type f -delete

fclean:	clean
	rm -f $(NAME)
	rm -f unit_tests
	@make fclean -C $(LIB_FILE)

re:	fclean all

precise:
	@make -C $(LIB_FILE)
	gcc -o $(NAME) $(MAIN_SRC) $(OBJ) $(INCLUDE) $(LIB) -Wall -Wextra

bonus:	$(OBJ)
	@make -C $(LIB_FILE)
	gcc -o $(NAME) $(MAIN_SRC) $(SRC) $(INCLUDE) $(LIB) -DBONUS

debug:	$(OBJ)
	@make -C $(LIB_FILE)
	gcc -o $(NAME) $(MAIN_SRC) $(SRC) $(INCLUDE) $(LIB) -DTESTS

tests_run:	re
	gcc -c $(SRC) $(INCLUDE) -DUNIT_TESTS --coverage
	gcc -c $(TESTS) $(INCLUDE)
	gcc -o unit_tests *.o -lcriterion -lgcov $(LIB)
	./unit_tests
	gcovr

%.o:	%.c
	@$(CC) -o $@ -c $< -W -g3 $(INCLUDE) && \
	echo "[ $(GREEN)$<\tCompiled !$(DEFAULT) ]" || \
	echo "[ $(RED)Fail compilation $<$(DEFAULT) ]"

.PHONY:	all clean fclean re tests_run bonus debug