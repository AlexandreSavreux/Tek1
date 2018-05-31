NAME	= ai

CC	= gcc

RM	= rm -f

SRCS	= ./src/function_info.c \
	  ./src/take_lidar.c \
	  ./src/main.c \
	  ./src/send_command.c	\
	  ./src/free_array.c	\
	  ./src/str_to_array.c \
	  ./src/my_get_nbr.c \
	  ./src/get_next_line.c \

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -W -Wall -Wextra

all: $(NAME) clean

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
