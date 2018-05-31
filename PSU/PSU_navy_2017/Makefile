SRC_DIR=        src

SRC=		$(SRC_DIR)/main.c \
			$(SRC_DIR)/map.c \
			$(SRC_DIR)/map2.c \
			$(SRC_DIR)/error.c \
			$(SRC_DIR)/connection.c \
			$(SRC_DIR)/player1.c \
			$(SRC_DIR)/player2.c \
			$(SRC_DIR)/signals.c \
			$(SRC_DIR)/get_next_line.c \
			$(SRC_DIR)/game.c

OBJ=            $(SRC: .c=.o)

CFLAGS=       	-L lib/my/ -lmy -I include -Wall -Wextra

NAME=           navy

all:            $(NAME)

$(NAME):        $(OBJ)
		make re -C lib/my/
		gcc -o $(NAME) $(SRC) $(CFLAGS)

clean:
		rm -f *.o

fclean:         clean
		rm -f $(NAME)

re:             fclean all
