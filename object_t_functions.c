/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** Functions related to object_t functions
*/
#include <stdlib.h>
#include "my_sokoban.h"

int search_line(char *line)
{
    int i = 0;

    while (line[i] != '\0') {
        if (line[i] == 'P')
            return (i);
        i++;
    }
    return (-1);
}

object_t *create_object(char **map)
{
    object_t *object;
    int i = 0;
    int y = 0;
    int result = -1;
    int has_found_object = 0;

    object = malloc(sizeof(object_t));
    while (result == -1) {
        result = search_line(map[i]);
        i++;
    }
    i--;
    object->pos.x = i;
    object->pos.y = result;
    return (object);
}