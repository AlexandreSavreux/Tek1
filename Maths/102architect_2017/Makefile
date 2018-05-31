SRC_DIR=        src

SRC=		$(SRC_DIR)/main.c \
		$(SRC_DIR)/calc.c \
		$(SRC_DIR)/my_ma_ops.c	\
		$(SRC_DIR)/my_error.c

OBJ=            $(SRC: .c=.o)

CFLAGS=       	-W -Wall -Wextra --coverage -I include -lm

NAME=           102architect

all:            $(NAME)

$(NAME):        $(OBJ)
		gcc -o $(NAME) $(SRC) $(CFLAGS)

clean:
		rm -f *.o

fclean:         clean
		rm -f $(NAME)

re:             fclean all
