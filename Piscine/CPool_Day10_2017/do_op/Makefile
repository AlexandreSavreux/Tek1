SRC_DIR=        $(realpath .)

SRC=            $(SRC_DIR)/my_do_op.c \

OBJ=            $(SRC: .c=.o)

CFLAGS=         -Wall -Wextra --coverage

NAME=           do-op

all:            $(NAME)

$(NAME):        $(OBJ)
		gcc -o $(NAME) $(OBJ) -L../lib/my/libmy.a -lmy

clean:
		rm -f $(OBJ)

fclean:         clean
		rm -f $(NAME)

re:             fclean all
