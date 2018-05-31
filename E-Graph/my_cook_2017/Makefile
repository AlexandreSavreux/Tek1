SRC_DIR=        src

NAME	= my_cook

CC	= gcc

RM	= rm -f

SRCS	= $(SRC_DIR)/main.c \
		  $(SRC_DIR)/preload_functions.c \
		  $(SRC_DIR)/error_handling.c \
		  $(SRC_DIR)/drawer.c \
		  $(SRC_DIR)/event_checker.c \
		  $(SRC_DIR)/game_events.c \
  		  $(SRC_DIR)/game_events2.c \
  		  $(SRC_DIR)/game_events3.c \
		  $(SRC_DIR)/display_ui.c \
		  $(SRC_DIR)/launch.c \
		  $(SRC_DIR)/score.c \
		  $(SRC_DIR)/buttons.c \
		  $(SRC_DIR)/loading_sprites.c \
		  $(SRC_DIR)/loading_songs.c \
  		  $(SRC_DIR)/on_button.c \
  		  $(SRC_DIR)/on_button2.c \
		  $(SRC_DIR)/loading_misc.c \
		  $(SRC_DIR)/window_events.c \

OBJS	= $(SRCS:.c=.o)

CFLAGS = -Llib/my -lmy -lc_graph_prog -I ./include/ -Wall -Wextra

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
