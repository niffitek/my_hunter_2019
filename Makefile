##
## EPITECH PROJECT, 2019
## Hunter
## File description:
## Makefile
##

SRC     =	src/main.c \
		    src/duck.c \
		    src/event.c \
		    src/mouse.c \
		    src/text.c \
		    src/create.c

OBJ	=	$(SRC:.c=.o)

NAME    =	my_hunter

CFLAGS += -pedantic

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -l csfml-graphics -l csfml-system -l csfml-audio -g3

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: my_hunter all clean fclean re
