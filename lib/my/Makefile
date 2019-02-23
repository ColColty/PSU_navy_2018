##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Do a file who compile for us
##

SRC	=	my_putchar.c	\
	my_putstr.c	\
	my_strlen.c	\
	my_strcmp.c \
	my_put_nbr.c \
	my_show_word_array.c \
	my_atoi.c	\
	my_revstr.c	\
	my_str_to_word_array.c  \

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

DEFAULT	=	\033[0m
GREEN	=	\033[0;32m
RED	=	\033[0;31m

all:	$(NAME)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ) && \
	echo "\n" "[ $(GREEN)$(NAME) created !$(DEFAULT) ]" || \
	echo "\n" "[ $(RED)$(NAME) failed...$(DEFAULT) ]"

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

%.o:	%.c
	@$(CC) -o $@ -c $< -W $(INCLUDE) && \
	echo "[ $(GREEN)$<\tCompiled !$(DEFAULT) ]" || \
	echo "[ $(RED)Fail compilation $<$(DEFAULT) ]"

re:	fclean all

.PHONY:	all clean fclean re
