##
## EPITECH PROJECT, 2017
## Makfile
## File description:
## 101pong
##

SRC	=	lib/my/my_revstr.c	\
		lib/my/puissance.c	\
		lib/my/char_to_float.c	\
		lib/my/my_carre.c	\
		lib/my/my_abs.c	\
		lib/my/char_to_int.c	\
		lib/my/my_strlen.c

SRC2	=	src/main.c	\
		src/manage_errors.c

OBJ	=	$(SRC:.c=.o)

LIB	=	./lib/my/libmy.a

NAME	=	101pong

all:	$(OBJ)
	ar rc $(LIB) $(OBJ)
	gcc $(SRC2) -I include -o $(NAME) -L./lib/my -lmy -lm -Wextra -Wall

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(LIB) $(NAME)

re:	fclean all
