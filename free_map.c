/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** Frees the map
*/
#include <stdlib.h>
#include "my_sokoban.h"

void free_map(map_t *map)
{
    int i = 0;
    int y = 0;

    while (i < map->size_y) {
        free(map->map[i]);
        i++;
    }
    //while (y < map->nb_objects) {
    //    free(map->objects[y]);
    //}
    free(map->objects);
    free(map);
}
