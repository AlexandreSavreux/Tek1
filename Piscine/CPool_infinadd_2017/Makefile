SRC_DIR=        $(realpath .)

SRC=           	$(SRC_DIR)/infin_add.c

OBJ=            $(SRC: .c=.o)

CFLAGS=         -W -Wall -Wextra --coverage

NAME=           infin_add

all:            $(NAME)

$(NAME):        $(OBJ)
		make re -C lib/my/
		gcc -o $(NAME) $(OBJ) -Llib/my -lmy -I include
clean:
		rm -f *.o

fclean:         clean
		rm -f $(NAME)

re:             fclean all
