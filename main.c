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
    map->nb_boxes = 0;
    map->nb_goals = 0;
    map->boxes = malloc(sizeof(object_t *) * 30);
    map->goals = malloc(sizeof(object_t *) * 30);
    int has_won = 0;

    if (ac != 2) {
        write(1, "Invalid number of arguments\n", 28);
        return (84);
    }
    load_map(av[1], map);
    has_won = run_game(map);
    my_put_nbr(has_won);
    free_map(map);
    return (0);
}
