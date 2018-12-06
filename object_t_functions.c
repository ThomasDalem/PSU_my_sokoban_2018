/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** Functions related to object_t functions
*/
#include <stdlib.h>
#include <curses.h>
#include <ncurses.h>
#include "my_sokoban.h"

int search_line(char const *line)
{
    int i = 0;

    while (line[i] != '\n') {
        if (line[i] == 'P')
            return (i);
        i++;
    }
    return (-1);
}

object_t *create_player(map_t *map)
{
    object_t *object;
    int i = 0;
    int result = -1;

    object = malloc(sizeof(object_t));
    while (result == -1 && i < map->size_y) {
        result = search_line(map->map[i]);
        i++;
    }
    i--;
    object->pos.x = i;
    object->pos.y = result;
    return (object);
}

object_t *create_object(position_t pos)
{
    object_t *object;

    object = malloc(sizeof(object_t));
    object->pos.x = pos.x;
    object->pos.y = pos.y;
    return (object);
}