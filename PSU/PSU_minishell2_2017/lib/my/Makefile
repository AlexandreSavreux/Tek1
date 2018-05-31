SRC_DIR=        .

SRC=		$(SRC_DIR)/my_putchar.c \
			$(SRC_DIR)/my_put_nbrbase.c \
			$(SRC_DIR)/my_put_u_nbrbase.c \
			$(SRC_DIR)/my_putstr.c \
			$(SRC_DIR)/my_put_nbr.c \
			$(SRC_DIR)/my_printf.c \
			$(SRC_DIR)/my_parser.c \
			$(SRC_DIR)/my_strlen.c \
			$(SRC_DIR)/my_strcpy.c \
			$(SRC_DIR)/my_strncpy.c \
			$(SRC_DIR)/my_strncmp.c \
			$(SRC_DIR)/my_strdup.c \
			$(SRC_DIR)/my_strcat.c \
			$(SRC_DIR)/my_strncat.c \
			$(SRC_DIR)/my_strstr.c \
			$(SRC_DIR)/my_atoi.c \
            $(SRC_DIR)/my_str_isnum.c \
             $(SRC_DIR)/my_str_isalpha.c \
			$(SRC_DIR)/my_array_free.c \
			$(SRC_DIR)/my_array_dup.c \
			$(SRC_DIR)/my_show_array.c \
			$(SRC_DIR)/my_str_to_wordarray.c\
			$(SRC_DIR)/my_puterror.c \
			$(SRC_DIR)/my_clean_str.c



OBJ=            $(SRC: .c=.o)

CFLAGS=       	-W -Wall -Wextra

NAME=           libmy.a

all:            $(NAME)

$(NAME):        $(OBJ)
		@gcc -c $(SRC) -Wall -Wextra -I ../../include
		@ar rc $(NAME) *.o

clean:
		@rm -f *.o

debug: 			fclean
		@gcc -c $(SRC) -Wall -Wextra -I ../../include -g
		@ar rc $(NAME) *.o

fclean:         clean
		@rm -f $(NAME)

re:             fclean all
