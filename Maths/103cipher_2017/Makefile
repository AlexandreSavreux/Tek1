SRC_DIR=        src

SRC=		$(SRC_DIR)/main.c \
			$(SRC_DIR)/my_ma_ops.c	\

OBJ=            $(SRC: .c=.o)

CFLAGS=       	-W -Wall -Wextra --coverage -I include -lm -L lib/my/ -lmy

NAME=           103cipher

all:            $(NAME)

$(NAME):        $(OBJ)
		make re -C lib/my/
		gcc -o $(NAME) $(SRC) $(CFLAGS)

clean:
		rm -f *.o

fclean:         clean
		rm -f $(NAME)

re:             fclean all
