SRC_DIR=        src

SRC=		$(SRC_DIR)/main.c \
			$(SRC_DIR)/error.c \
			$(SRC_DIR)/get_next_line.c \
			$(SRC_DIR)/drawer.c \
			$(SRC_DIR)/goal.c \
			$(SRC_DIR)/ai.c

OBJ=            $(SRC: .c=.o)

CFLAGS=       	-L lib/my/ -lmy -I include -W -Wall -Wextra

NAME=           matchstick

all:            $(NAME)

$(NAME):        $(OBJ)
		make re -C lib/my/
		gcc -o $(NAME) $(SRC) $(CFLAGS)

clean:
		rm -f *.o

fclean:         clean
		rm -f $(NAME)

re:             fclean all
