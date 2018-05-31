##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

SRC_DIR=        ./src/

SRC=		$(SRC_DIR)/main.c 		\
		$(SRC_DIR)/init_cor.c		\
		$(SRC_DIR)/get_name_comment.c

OBJ=            $(SRC: .c=.o)

CFLAGS=       	-L lib/my/ -lmy -I./include -Wall -Wextra

NAME=           asm

all:            $(NAME)

$(NAME):        $(OBJ)
		make re -C lib/my/
		gcc -g -o $(NAME) $(SRC) $(CFLAGS)

clean:
		rm -f *.o
		rm -f lib/my/*.o

fclean:         clean
		rm -f $(NAME)

re:             fclean all
