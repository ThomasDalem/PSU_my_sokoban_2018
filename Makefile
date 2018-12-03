##
## EPITECH PROJECT, 2018
## PSU_my_sokoban_2018
## File description:
## Makefile
##

SRC		=		main.c				\
				game_manager.c		\
				manage_inputs.c		\
				free_map.c			\
				screen_functions.c	\
				object_t_functions.c\
				my_strlen.c			\
				display_player.c	\
				box_movement.c		\
				map_loader.c

NAME	=		my_sokokan

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) -g -Iinclude -lncurses
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all