SRC_DIR=   src

NAME	= tetris

CC	= gcc

RM	= rm -f

SRCS	= $(SRC_DIR)/main.c \
		  $(SRC_DIR)/display.c \
		  $(SRC_DIR)/open.c \
		  $(SRC_DIR)/env.c \
		  $(SRC_DIR)/map.c \
		  $(SRC_DIR)/recup_touch.c \
		  $(SRC_DIR)/get_next_line.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -L lib/my -lmy -lncurses -I include -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
		make re -C lib/my
		$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
