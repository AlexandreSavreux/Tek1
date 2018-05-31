SRC_DIR=        $(realpath ..)

SRC=            $(SRC_DIR)/XXXX.c
		$(SRC_DIR)/YYYY.c

OBJ=            $(SRC: .c=.o)

CFLAGS=         -Wall -Wextra --coverage

LDFLAGS=        -lcriterion -lgcov

NAME=           units

all:            $(NAME)

$(NAME):        $(OBJ)
		cc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		rm -f $(OBJ)

fclean:         clean
		rm -f $(NAME)

re:             fclean all
