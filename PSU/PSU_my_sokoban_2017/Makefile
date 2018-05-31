SRC_DIR=        src

SRC=		$(SRC_DIR)/main.c \
			$(SRC_DIR)/calc.c \
			$(SRC_DIR)/check_errors.c \
			$(SRC_DIR)/game.c \
			$(SRC_DIR)/move.c \
			$(SRC_DIR)/input.c \


OBJ=            $(SRC: .c=.o)

CFLAGS=       	-g -L lib/my/ -lmy -I include -lncurses -Wall -Wextra -pedantic --coverage

NAME=           my_sokoban

all:            $(NAME)

$(NAME):        $(OBJ)
		make re -C lib/my/
		gcc -o $(NAME) $(SRC) $(CFLAGS)

clean:
		rm -f *.o

fclean:         clean
		rm -f $(NAME)

re:             fclean all
