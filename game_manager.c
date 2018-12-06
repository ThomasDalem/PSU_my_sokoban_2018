/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** Functions to manage the game
*/
#include <curses.h>
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_sokoban.h"

int run_game(map_t *map, int *restart)
{
    int input = 0;
    object_t *player = create_player(map);
    int pos_y = map->size_y;
    int has_won = 1;
    int is_stuck = 0;

    while (*restart != 1 && has_won != 0 && is_stuck == 0) {
        for (int i = 0; i < pos_y; i++)
            printw(map->map[i]);
        input = getch();
        check_inputs(input, map, player, restart);
        display_goals(map, player);
        is_stuck = check_if_stuck(map);
        has_won = check_if_won(map);
        refresh();
        clear();
    }
    free(player);
    return (has_won);
}
