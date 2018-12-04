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

int search_line(char *line, int type)
{
    int i = 0;
    char char_to_search;

    if (type == 1)
        char_to_search = 'P';
    if (type == 2)
        char_to_search = 'X';
    if (type == 3) {
        printw("OK");
        char_to_search = 'O';
    }
    while (line[i] != '\0') {
        if (line[i] == char_to_search)
            return (i);
        i++;
    }
    return (-1);
}

object_t *create_player(map_t *map, int type)
{
    object_t *object;
    int i = 0;
    int y = 0;
    int result = -1;

    object = malloc(sizeof(object_t));
    while (result == -1) {
        result = search_line(map->map[i], type);
        i++;
    }
    i--;
    object->type = type;
    object->pos.x = i;
    object->pos.y = result;
    return (object);
}

object_t *create_object(int type, position_t pos)
{
    object_t *object;
    int i = 0;
    int y = 0;

    object = malloc(sizeof(object_t));
    object->type = type;
    object->pos.x = pos.x;
    object->pos.y = pos.y;
    return (object);
}