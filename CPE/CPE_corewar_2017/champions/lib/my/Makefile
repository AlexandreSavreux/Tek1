SRC_DIR=        .

SRC=		$(SRC_DIR)/my_putchar.c \
			$(SRC_DIR)/my_put_nbrbase.c \
			$(SRC_DIR)/my_put_u_nbrbase.c \
			$(SRC_DIR)/my_putstr.c \
			$(SRC_DIR)/my_put_nbr.c \
			$(SRC_DIR)/my_printf.c \
			$(SRC_DIR)/my_parser.c \
			$(SRC_DIR)/my_strlen.c \
			$(SRC_DIR)/my_strncpy.c \
			$(SRC_DIR)/my_atoi.c \
			$(SRC_DIR)/my_str_isnum.c


OBJ=            $(SRC: .c=.o)

CFLAGS=       	-W -Wall -Wextra

NAME=           libmy.a

all:            $(NAME)

$(NAME):        $(OBJ)
		@gcc -c $(SRC) -Wall -Wextra -I ../../include
		@ar rc $(NAME) *.o

clean:
		@rm -f *.o

fclean:         clean
		@rm -f $(NAME)

re:             fclean all
