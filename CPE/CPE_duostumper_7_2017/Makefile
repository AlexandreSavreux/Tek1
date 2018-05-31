##
## EPITECH PROJECT, 2017
## Make-make's Makefile
## File description:
## By Ndr
##

###############
#  VARIABLES  #
###############

#Nom du projet (binaire)
NAME=		hangman

#Répertoire des sources (.c)
SRC_DIR=	$(realpath ./src)

#Répertoire de la lib (.a)
LIB_DIR=	$(realpath ./lib/my)

#Répertoire des includes (.h)
INC_DIR=	$(realpath ./include)

#Fichiers sources à compiler
#(Par défaut, compile tous les .c du dossier src)
SRC=		$(SRC_DIR)/main.c			\
		$(SRC_DIR)/game.c			\
		$(SRC_DIR)/game_loop.c			\
		$(SRC_DIR)/get_my_file.c		\
		$(SRC_DIR)/prepare_my_struct.c

#Lib à inclure
LIB=		my

#Fichiers objets (.o)
OBJ=		$(SRC:.c=.o)

#Arguments gcc (Ajoutez ici les libs supplémentaires)
#Ex: -lm pour math.h, -lncurses pour ncurses, ...
GCC_ARG=	-L$(LIB_DIR) -l$(LIB) -I$(INC_DIR)


############
#  RÈGLES  #
############

all:		$(NAME)

#Compilation normale (lib + binaire)
$(NAME):
		make -C $(LIB_DIR)
		@echo -e  "\n\033[1m\033[36mCompiling $(NAME)...\033[0m"
		gcc -o $(NAME) $(SRC) $(GCC_ARG)

#Efface les .o dans lib/my
clean:
		make clean -C $(LIB_DIR)
		@echo -e  "\n\033[1m\033[33mCleaning files...\033[0m"
		rm -f $(OBJ)

#Efface le binaire et la lib
fclean:
		@echo -e  "\n\033[1m\033[33mCleaning files and binary...\033[0m"
		rm -f $(NAME)
		make fclean -C $(LIB_DIR)

re:		fclean all
