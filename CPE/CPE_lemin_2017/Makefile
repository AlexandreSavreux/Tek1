SRC_DIR=        src

NAME	= lem_in

CC	= gcc

RM	= rm -f

SRCS	= $(SRC_DIR)/main.c \
			$(SRC_DIR)/opener.c	\
			$(SRC_DIR)/print_tunnel.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -Llib/my -lmy -I ./include/ -Wall -Wextra -g

all: $(NAME)

$(NAME): $(OBJS)
		@make re -C lib/my
		@$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
