/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** Manages inputs of the user
*/
#include <curses.h>
#include <ncurses.h>
#include <unistd.h>
#include "my_sokoban.h"

void move_vertical(map_t *map, object_t *player, int input)
{
    position_t dir;

    if (input == KEY_UP) {
        dir.x = 0;
        dir.y = -1;
        if (move_boxes(player, map, dir) != -1)
        change_player_pos(player, map, dir);
    }
    if (input == KEY_DOWN) {
        dir.x = 0;
        dir.y = 1;
        if (move_boxes(player, map, dir) != -1)
        change_player_pos(player, map, dir);
    }
}

void move_horizontal(map_t *map, object_t *player, int input)
{
    position_t dir;

    if (input == KEY_LEFT) {
        dir.x = -1;
        dir.y = 0;
        if (move_boxes(player, map, dir) != -1)
        change_player_pos(player, map, dir);
    }
    if (input == KEY_RIGHT) {
        dir.x = 1;
        dir.y = 0;
        if (move_boxes(player, map, dir) != -1)
        change_player_pos(player, map, dir);
    }
}

void check_inputs(int input, map_t *map, object_t *player, int *restart)
{
    if (input == KEY_UP || input == KEY_DOWN)
        move_vertical(map, player, input);
    else if (input == KEY_LEFT || input == KEY_RIGHT)
        move_horizontal(map, player, input);
    if (input == ' ')
        *restart = 1;
}
