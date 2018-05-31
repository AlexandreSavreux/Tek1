SRC_DIR=        src

SRC=		$(SRC_DIR)/main.c \
			$(SRC_DIR)/calc.c \
			$(SRC_DIR)/error.c \


OBJ=            $(SRC: .c=.o)

CFLAGS=       	-lm -L lib/my/ -lmy -I include -W -Wall -Wextra

NAME=           106bombyx

all:            $(NAME)

$(NAME):        $(OBJ)
		make re -C lib/my/
		gcc -o $(NAME) $(SRC) $(CFLAGS)

clean:
		rm -f *.o

fclean:         clean
		rm -f $(NAME)

re:             fclean all
