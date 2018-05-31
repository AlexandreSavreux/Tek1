SRC_DIR=        src

SRC=		$(SRC_DIR)/my_atoi.c \
		$(SRC_DIR)/my_swap.c \
		$(SRC_DIR)/my_swappers.c \
		$(SRC_DIR)/my_putstr.c \
		$(SRC_DIR)/my_put_nbr.c \
		$(SRC_DIR)/my_putchar.c \
		$(SRC_DIR)/my_strlen.c \
		$(SRC_DIR)/my_pushswap.c \
		$(SRC_DIR)/my_show_list.c \

OBJ=            $(SRC: .c=.o)

CFLAGS=       	-W -Wall -Wextra --coverage -I include

NAME=           push_swap

all:            $(NAME)

$(NAME):        $(OBJ)
		gcc -o $(NAME) $(SRC) $(CFLAGS)

clean:
		rm -f *.o

fclean:         clean
		rm -f $(NAME)

re:             fclean all
