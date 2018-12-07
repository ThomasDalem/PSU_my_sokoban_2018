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
				display_goals.c		\
				check_if_won.c 		\
				box_check_stuck.c	\
				my_put_nbr.c		\
				can_move.c			\
				my_putchar.c 		\
				get_sizes.c			\
				check_malloc.c		\
				check_args.c		\
				map1d_to_map2d.c	\
				map_loader.c

NAME	=		my_sokoban

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) -Wall -Wextra -g -Iinclude -lncurses
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
