SRC_DIR=        src

SRC=		$(SRC_DIR)/my_putchar.c \
		$(SRC_DIR)/my_putstr.c \
		$(SRC_DIR)/my_put_nbr.c \
		$(SRC_DIR)/my_strlen.c \
		$(SRC_DIR)/main.c

OBJ=            $(SRC: .c=.o)

CFLAGS=       	-I include -L lib/my -lmy -W -Wall -Wextra

NAME=           my_ls

all:            $(NAME)

$(NAME):        $(OBJ)
		make re -C lib/my
		gcc -o $(NAME) $(SRC) $(CFLAGS)

clean:
		rm -f *.o

fclean:         clean
		rm -f $(NAME)

re:             fclean all
