SRC_DIR=      	..


# Must list all project files without the main() function
# Criterion uses its own main() ;
# having a main() in any .c file will have the build fail


SRC=            $(SRC_DIR)/match.c \

SRC_UT_DIR=     .

# Must list all files containing unit tests

SRC_UT=         $(SRC_UT_DIR)/test_main.c \

OBJ=            $(SRC:.c=.o) $(SRC_UT:.c=.o)

CFLAGS=         -Wall -Wextra --coverage

LDFLAGS=        -lcriterion -lgcov

NAME=           units

all:            $(NAME)

$(NAME):        $(OBJ)
		gcc -o $(NAME) $(OBJ) $(LDFLAGS)
clean:
		rm -f $(OBJ)

fclean:         clean
		rm -f $(NAME)

re:             fclean all
