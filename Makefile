##
## EPITECH PROJECT, 2024
## myhunter
## File description:
## Makefile
##

SRC    =    main.c   \
            src/*.c  \

NAME    =    my_hunter

CFLAGS    =    -W -Wall -Wextra

CSFMLFLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all:    $(NAME)

$(NAME):
	gcc -g -o $(NAME) $(SRC) $(CFLAGS) $(CSFMLFLAGS)

clean:
	rm -f $(OBJ)

fclean:
	make clean
	rm -f $(NAME)

re: fclean all
