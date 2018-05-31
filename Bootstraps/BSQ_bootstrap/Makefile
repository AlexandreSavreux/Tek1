SRC_DIR=        src

SRC=		$(SRC_DIR)/main.c \
		$(SRC_DIR)/my_put_nbr.c \
		$(SRC_DIR)/my_putchar.c \

OBJ=            $(SRC: .c=.o)

CFLAGS=       	-W -Wall -Wextra --coverage -I include

NAME=           BSQ

all:            $(NAME)

$(NAME):        $(OBJ)
		gcc -o $(NAME) $(SRC) $(CFLAGS)

clean:
		rm -f *.o

fclean:         clean
		rm -f $(NAME)

re:             fclean all
