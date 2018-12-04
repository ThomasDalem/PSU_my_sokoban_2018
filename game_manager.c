/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** Functions to manage the game
*/
#include <curses.h>
#include <ncurses.h>
#include <unistd.h>
#include "my_sokoban.h"

int run_game(map_t *map)
{
    int input = 0;
    object_t *player = create_player(map, 1);
    int pos_x = map->size_x;
    int pos_y = map->size_y;
    int has_won = -1;

    init_screen();
    while (input != ' ' && has_won != 1) {
        for (int i = 0; i < map->size_y; i++)
            mvprintw(LINES / 2 - pos_y / 2 + i, COLS / 2 - pos_y / 2, map->map[i]);
        printw("O pos x = %d\n", map->goals[0]->pos.x);
        printw("X pos x = %d", map->boxes[0]->pos.x);
        input = getch();
        check_inputs(input, map, player);
        display_goals(map, player);
        has_won = check_if_won(map);
        refresh();
    }
    end_screen();
    return (has_won);
}
