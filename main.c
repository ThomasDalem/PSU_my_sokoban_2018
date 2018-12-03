/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** main function for the my_sokoban program
*/
#include <stdlib.h>
#include <unistd.h>
#include "my_sokoban.h"

int main (int ac, char **av)
{
    map_t *map = malloc(sizeof(map_t));
    map->nb_objects = 0;
    map->objects = malloc(sizeof(object_t *) * 30);

    if (ac != 2) {
        write(1, "Invalid number of arguments\n", 28);
        return (84);
    }
    load_map(av[1], map);
    run_game(map);
    free_map(map);   
}
