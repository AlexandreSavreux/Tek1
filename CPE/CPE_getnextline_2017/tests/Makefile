SRC_DIR=      	..


# Must list all project files without the main() function
# Criterion uses its own main() ;
# having a main() in any .c file will have the build fail


SRC=            $(SRC_DIR)/get_next_line.c \


SRC_UT_DIR=     .

# Must list all files containing unit tests

SRC_UT=         $(SRC_UT_DIR)/main_test.c \

OBJ=            $(SRC:.c=.o) $(SRC_UT:.c=.o)

CFLAGS=         -Wall -Wextra --coverage -I../include

LDFLAGS=        -lcriterion -lgcov

NAME=           units

all:            $(NAME)

$(NAME):        $(OBJ)
		gcc -o $(NAME) $(OBJ) $(LDFLAGS) -I ../include
clean:
		rm -f $(OBJ)
		rm -f *.gcno
		rm -f *.gcda

fclean:         clean
		rm -f $(NAME)

re:             fclean all
