SRC_DIR=        src

SRC=		$(SRC_DIR)/main.c \
			$(SRC_DIR)/functions.c \
			$(SRC_DIR)/builtins.c \
			$(SRC_DIR)/my_cmd_cat.c \
			$(SRC_DIR)/builtins/my_cd.c \
			$(SRC_DIR)/builtins/my_exit.c \
			$(SRC_DIR)/builtins/my_env.c \
			$(SRC_DIR)/builtins/my_setenv.c \
			$(SRC_DIR)/builtins/my_unsetenv.c \
			$(SRC_DIR)/env/setenv.c \
			$(SRC_DIR)/env/unsetenv.c \
			$(SRC_DIR)/utils/check_if_cmd_exist.c \
			$(SRC_DIR)/utils/advanced_parsing.c \
			$(SRC_DIR)/utils/signals.c \
			$(SRC_DIR)/utils/recup_from_env.c \
			$(SRC_DIR)/parsing.c

OBJ=            $(SRC: .c=.o)

CFLAGS=       	-L lib/my/ -lmy -I include -W -Wall -Wextra

NAME=           mysh

all:            $(NAME)

$(NAME):        $(OBJ)
		make re -C lib/my/
		gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		rm -f *.o

debug:
		make debug -C lib/my/
		gcc -o $(NAME) $(SRC) $(CFLAGS) -g

fclean:         clean
		rm -f $(NAME)

re:             fclean all
