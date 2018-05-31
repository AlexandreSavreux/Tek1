##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile of 109titration
##

SRC	=	src/main.c \
        	src/second_file.c	\
	src/sort_number.c

OBJ	=	$(SRC:.c=.o)

NAME	=	109titration

CFLAGS = -I include -lm

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(SRC) $(CFLAGS)
	rm src/*.o

clean:
	rm src/*.o

fclean:
	rm -f $(NAME)
	rm src/*.o

re: fclean all
