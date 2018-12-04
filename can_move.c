/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** Functions to check if a box can move in given direction
*/
#include "my_sokoban.h"

int can_move_up(object_t *box, char **map)
{
    position_t pos;
    char new_pos_char;

    pos.x = 0;
    pos.y = -1;
    new_pos_char = map[box->pos.y + pos.y][box->pos.x + pos.x];
    if (can_move(new_pos_char))
        return (1);
    return (0);
}

int can_move_down(object_t *box, char **map)
{
    position_t pos;
    char new_pos_char;

    pos.x = 0;
    pos.y = 1;
    new_pos_char = map[box->pos.y + pos.y][box->pos.x + pos.x];
    if (can_move(new_pos_char))
        return (1);
    return (0);
}

int can_move_left(object_t *box, char **map)
{
    position_t pos;
    char new_pos_char;

    pos.x = -1;
    pos.y = 0;
    new_pos_char = map[box->pos.y + pos.y][box->pos.x + pos.x];
    if (can_move(new_pos_char))
        return (1);
    return (0);
}

int can_move_right(object_t *box, char **map)
{
    position_t pos;
    char new_pos_char;

    pos.x = 1;
    pos.y = 0;
    new_pos_char = map[box->pos.y + pos.y][box->pos.x + pos.x];
    if (can_move(new_pos_char))
        return (1);
    return (0);
}