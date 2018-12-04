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
    object_t *player = create_player(map);
    int pos_x = map->size_x;
    int pos_y = map->size_y;
    int has_won = 1;
    int is_stuck = 0;

    init_screen();
    while (input != ' ' && has_won != 0 && is_stuck == 0) {
        for (int i = 0; i < pos_y; i++)
            mvprintw(LINES / 2 - pos_y / 2 + i, COLS / 2 - pos_y / 2, map->map[i]);
        input = getch();
        check_inputs(input, map, player);
        printw("Player x : %d\n Player y : %d", player->pos.x, player->pos.y);
        display_goals(map, player);
        is_stuck = check_if_stuck(map);
        has_won = check_if_won(map);
        refresh();
    }
    end_screen();
    return (has_won);
}
