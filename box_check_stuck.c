/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** Functions to check if the boxes are stuck
*/
#include "my_sokoban.h"

int try_move(object_t *box, map_t *map)
{
    if (can_move_left(box, map->map) == 0 && can_move_up(box, map->map) == 0)
        return (0);
    if (can_move_left(box, map->map) == 0 && can_move_down(box, map->map) == 0)
        return (0);
    if (can_move_right(box, map->map) == 0 && can_move_up(box, map->map) == 0)
        return (0);
    if (can_move_right(box, map->map) == 0 && can_move_down(box, map->map) == 0)
        return (0);
    return (1);
}

int check_if_stuck(map_t *map)
{
    for (int i = 0; i < map->nb_boxes; i++) {
        if (try_move(map->boxes[i], map) == 1)
            return (0);
    }
    return (1);
}