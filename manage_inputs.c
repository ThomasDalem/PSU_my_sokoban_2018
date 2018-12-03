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

void move_vertical(char **map, object_t *player, int input)
{
    if (input == KEY_UP) {
        if (map[player->pos.y - 1][player->pos.x] != '#') {
            map[player->pos.y - 1][player->pos.x] = 'P';
            map[player->pos.y][player->pos.x] = ' ';
            player->pos.y--;
        }
    }
    if (input == KEY_DOWN) {
        if (map[player->pos.y + 1][player->pos.x] != '#') {
            map[player->pos.y + 1][player->pos.x] = 'P';
            map[player->pos.y][player->pos.x] = ' ';
            player->pos.y++;
        }
    }
}

void move_horizontal(char **map, object_t *player, int input)
{
    if (input == KEY_LEFT) {
        if (map[player->pos.y][player->pos.x - 1] != '#') {
            map[player->pos.y][player->pos.x - 1] = 'P';
            map[player->pos.y][player->pos.x] = ' ';
            player->pos.x--;
        }
    }
    if (input == KEY_RIGHT) {
        if (map[player->pos.y][player->pos.x + 1] != '#') {
            map[player->pos.y][player->pos.x + 1] = 'P';
            map[player->pos.y][player->pos.x] = ' ';
            player->pos.x++;
        }
    }
}

void check_inputs(int input, char **map, object_t *player)
{
    if (input == KEY_UP || input == KEY_DOWN) {
        move_vertical(map, player, input);
    }
    else if (input == KEY_LEFT || input == KEY_RIGHT) {
        move_horizontal(map, player, input);
    }
}
