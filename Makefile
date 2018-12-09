##
## EPITECH PROJECT, 2018
## PSU_my_sokoban_2018
## File description:
## Makefile
##

SRC		=		game_manager.c		    \
				manage_inputs.c		    \
				free_map.c		    \
				screen_functions.c	    \
				object_t_functions.c	    \
				display_player.c	    \
				box_movement.c		    \
				display_goals.c		    \
				check_if_won.c		    \
				box_check_stuck.c	    \
				can_move.c		    \
				get_sizes.c		    \
				check_malloc.c		    \
				check_args.c		    \
				map1d_to_map2d.c	    \
				map_loader.c		    \
				check_map.c

LIB_SRC		=		my_put_nbr.c		    \
				my_putchar.c		    \
				my_strlen.c

TESTS_SRC	=		tests/map_loading_tests.c   \
				tests/sizes_tests.c	    \
				tests/check_win_or_loose.c

TEST_FLAGS	=		--coverage -Iinclude -lncurses -lcriterion

FLAGS		=		-Wall -Wextra -g -Iinclude -lncurses

NAME		=		my_sokoban

all: $(NAME)

$(NAME):
	gcc -o $(NAME) main.c $(SRC) $(LIB_SRC) $(FLAGS)
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

tests_run:
	gcc -o unit_tests $(TESTS_SRC) $(SRC) $(TEST_FLAGS)
	./unit_tests
