SRC_DIR=        src

NAME	= my_cook

CC	= gcc

RM	= rm -f

SRCS	= $(SRC_DIR)/main.c \

OBJS	= $(SRCS:.c=.o)

CFLAGS = -Llib/my -lmy -lc_graph_prog -I ./include/ -W -Wall -Wextra

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
