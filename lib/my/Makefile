##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Do a file who compile for us
##

SRC	=	my_putchar.c	\
	my_putstr.c	\
	my_strlen.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

%.o:	%.c
	@echo "Compiling $@..."
	@$(CC) -o $@ -c $< -W

re:	fclean all

.PHONY:	all clean fclean re
