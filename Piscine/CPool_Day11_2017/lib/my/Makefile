SRC_DIR=        .

SRC=            $(SRC_DIR)/my_compute_power_rec.c \
		$(SRC_DIR)/my_compute_square_root.c \
		$(SRC_DIR)/my_find_prime_sup.c \
		$(SRC_DIR)/my_getnbr.c \
		$(SRC_DIR)/my_isneg.c \
		$(SRC_DIR)/my_is_prime.c \
		$(SRC_DIR)/my_putchar.c \
		$(SRC_DIR)/my_put_nbr.c \
		$(SRC_DIR)/my_putstr.c \
		$(SRC_DIR)/my_revstr.c \
		$(SRC_DIR)/my_showmem.c \
		$(SRC_DIR)/my_showstr.c \
		$(SRC_DIR)/my_sort_int_array.c \
		$(SRC_DIR)/my_strcapitalize.c \
		$(SRC_DIR)/my_strcat.c \
		$(SRC_DIR)/my_strcmp.c \
		$(SRC_DIR)/my_strcpy.c \
		$(SRC_DIR)/my_str_isalpha.c \
		$(SRC_DIR)/my_str_islower.c \
		$(SRC_DIR)/my_str_isnum.c \
		$(SRC_DIR)/my_str_isprintable.c \
		$(SRC_DIR)/my_str_isupper.c \
		$(SRC_DIR)/my_strlen.c \
		$(SRC_DIR)/my_strlowcase.c \
		$(SRC_DIR)/my_strncat.c \
		$(SRC_DIR)/my_strncmp.c \
		$(SRC_DIR)/my_strncpy.c \
		$(SRC_DIR)/my_strstr.c \
		$(SRC_DIR)/my_strupcase.c \
		$(SRC_DIR)/my_swap.c \

OBJ=            $(SRC: .c=.o)

CFLAGS=         -Wall -Wextra --coverage

NAME=           libmy.a

all:            $(NAME)

$(NAME):        $(OBJ)
		gcc -c $(SRC)
		ar rc libmy.a *.o

clean:
		rm -f *.o

fclean:         clean
		rm -f $(NAME)

re:             fclean all
