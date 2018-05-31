SRC_DIR=        .

SRC=		$(SRC_DIR)/main.c \
			$(SRC_DIR)/get_next_line.c \


OBJ=            $(SRC: .c=.o)

CFLAGS=       	-W -Wall -Wextra

NAME=           get_next_line

all:            $(NAME)

$(NAME):        $(OBJ)
		gcc -o $(NAME) $(SRC) $(CFLAGS)

clean:
		rm -f *.o

fclean:         clean
		rm -f $(NAME)

re:             fclean all
