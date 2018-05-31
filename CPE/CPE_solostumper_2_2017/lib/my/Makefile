SRC_DIR=        .

SRC=		$(SRC_DIR)/my_putchar.c \
		$(SRC_DIR)/my_put_nbrbase.c \
		$(SRC_DIR)/my_put_u_nbrbase.c \
		$(SRC_DIR)/my_putstr.c \
		$(SRC_DIR)/my_put_nbr.c \
		$(SRC_DIR)/my_strcat.c \
		$(SRC_DIR)/my_strdup.c \
		$(SRC_DIR)/my_strlen.c

OBJ=            $(SRC: .c=.o)

CFLAGS=       	-W -Wall -Wextra --coverage

NAME=           libmy.a

all:            $(NAME)

$(NAME):        $(OBJ)
		@gcc -c $(SRC) -W -Wall -Wextra -I ../../include
		@ar rc $(NAME) *.o

clean:
		@rm -f *.o

fclean:         clean
		@rm -f $(NAME)

re:             fclean all
