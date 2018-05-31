NAME	= program

CC	= gcc

RM	= rm -f

SRCS	= ./simple_window.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -lc_graph_prog -I ./include/

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
