SRC_DIR=        $(realpath .)

SRC=           	$(SRC_DIR)/my_float.c \
		$(SRC_DIR)/my_second_rush.c

OBJ=            $(SRC: .c=.o)

CFLAGS=         -W -Wall -Wextra --coverage

NAME=           rush2

all:            $(NAME)

$(NAME):        $(OBJ)
		gcc -o $(NAME) $(OBJ) -Llib/my -lmy -I include
clean:
		rm -f *.o

fclean:         clean
		rm -f $(NAME)

re:             fclean all
