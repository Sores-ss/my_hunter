##
## EPITECH PROJECT, 2024
## myhunter
## File description:
## Makefile
##

SRC    =    main.c   \
            src/*.c  \

NAME    =    my_hunter

CFLAGS    =    -W -Wall -Wextra -lcsfml-graphics -lcsfml-window -lcsfml-system

all:    $(NAME)

$(NAME):
	gcc -g -o $(NAME) $(SRC) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:
	make clean
	rm -f $(NAME)

re: fclean all
