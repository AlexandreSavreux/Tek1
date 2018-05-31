SRC_DIR=        $(realpath .)

SRC=		$(SRC_DIR)/main.c \
		$(SRC_DIR)/disp_stdarg.c \

OBJ=            $(SRC: .c=.o)

CFLAGS=       	-W -Wall -Wextra --coverage

NAME=           calc

all:            $(NAME)

$(NAME):        $(OBJ)
		make re -C lib/my/
		gcc -o $(NAME) $(OBJ) -Llib/my -lmy -I include
clean:
		rm -f *.o
		make clean -C lib/my/

fclean:         clean
		rm -f $(NAME)

re:             fclean all
