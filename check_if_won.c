/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** Functions to check if the player won
*/
#include <ncurses.h>
#include <curses.h>
#include "my_sokoban.h"

int check_if_have_box(map_t *map, object_t *goal)
{
    int have_box_in = 0;

    for (int i = 0; i < map->nb_boxes; i++) {
        if (is_same_pos(goal->pos, map->boxes[i]->pos))
            have_box_in = 1;
    }
    return (have_box_in);
}

int check_if_won(map_t *map)
{
    int have_box = 0;

    for (int i = 0; i < map->nb_goals; i++) {
        have_box = check_if_have_box(map, map->goals[i]);
        if (have_box == 0)
            return (1);
    }
    return (0);
}
