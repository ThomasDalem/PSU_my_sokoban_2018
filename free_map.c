/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** Frees the map
*/
#include <stdlib.h>
#include "my_sokoban.h"

void free_map(char **map)
{
    int i = 0;

    while (i < 10) {
        free(map[i]);
        i++;
    }
    free(map);
}
