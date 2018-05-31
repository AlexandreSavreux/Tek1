##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## compiles and cleans
##

SRC	=	src/main.c      \
		src/create_elem.c       \
		src/events.c    \
		src/create_inventory.c  \
		src/user_item.c \
		src/display_menu.c      \
		src/destroy.c   \
		src/display.c   \
		src/rpg.c       \
		src/init_values.c	\
		src/create_stats.c      \
		src/stats.c     \
		src/quest.c	\
		src/create_quests.c	\
		src/display_inventory.c \
		src/items.c	\
		src/pickup.c	\
		src/item_actions/ak47.c	\
		src/item_actions/cut.c  \
		src/item_actions/rocket_movement.c  \
		src/item_actions/cut_movement.c \
		src/item_actions/rocket_launcher.c      \
		src/pnj/ak47/ak47_man.c	\
		src/pnj/ak47/ak47_warehouse.c  \
		src/pnj/ak47/ak47_warehouse_ext.c  \
		src/pnj/ak47/ak47_manage.c  \
		src/pnj/ak47/ak47_man_ext.c \
		src/pnj/ak47/ak47_cafet.c   \
		src/pnj/ak47/ak47_cafet_ext.c   \
		src/pnj/ak47/ak47_hall.c    \
		src/pnj/ak47/ak47_hall_ext.c    \
		src/pnj/ak47/manage_room_pnj.c  \
		src/pnj/rocket/taliban_manage.c \
		src/pnj/rocket/taliban_kitchen.c    \
		src/pnj/rocket/taliban_kitchen_ext.c    \
		src/pnj/rocket/manage_room_taliban_pnj.c    \
		src/pnj/rocket/rocket_pnj.c \
		src/pnj/rocket/hitbox_rocket.c  \
		src/pnj/rocket/taliban_warehouse.c  \
		src/pnj/rocket/taliban_warehouse_ext.c  \
		src/pnj/rocket/taliban_cafet.c  \
		src/pnj/rocket/taliban_cafet_ext.c  \
		src/pnj/rocket/taliban_hall.c   \
		src/pnj/rocket/taliban_hall_ext.c	\
		src/map/check_map_change.c	\
		src/map/movements.c     \
		src/map/create_map.c    \
		src/map/change_map.c    \
		src/menu/display_logo.c  \
		src/menu/event_main_menu.c   \
		src/menu/menu.c  \
		src/menu/resize_asset.c  \
		src/menu/select_chicken.c    \
		src/menu/select_chicken_second.c \
		src/menu/settings_main_menu.c    \
		src/menu/settings_main_menu_second.c    \
		src/menu/display_logo_second.c  \
		src/pnj/damage_managing.c   \
		src/pnj/time_damage.c   \
		src/pnj/damage_managing_terrorist.c \
		src/item_actions/rocket_hitbox.c    \
		src/pnj/manage_chicken_life.c

CFLAGS	=	-I include -lc_graph_prog -Wextra -Wall -g

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

exe:	re
	./$(NAME)
