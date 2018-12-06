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
    for (int i = 0; i < map->size_y; i++)
        free(map->map[i]);
    for (int i = 0; i < map->nb_boxes; i++)
        free(map->boxes[i]);
    for (int i = 0; i < map->nb_goals; i++)
        free(map->goals[i]);
    free(map->boxes);
    free(map->goals);
    free(map->map);
    free(map);
}
