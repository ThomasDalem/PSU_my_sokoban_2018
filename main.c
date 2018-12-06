/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** main function for the my_sokoban program
*/
#include <ncurses.h>
#include <curses.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_sokoban.h"

int main (int ac, char **av)
{
    map_t *map;
    int has_won = 0;
    int restart = 1;

    check_arguments(ac);
    init_screen();
    while (restart == 1) {
        restart = 0;
        map = malloc(sizeof(map_t));
        map->nb_boxes = 0;
        map->nb_goals = 0;
        map->boxes = malloc(sizeof(object_t *) * 30);
        map->goals = malloc(sizeof(object_t *) * 30);
        map->map = load_map(av[1], map);
        has_won = run_game(map, &restart);
        my_put_nbr(map->size_y);
        free_map(map);
        clear();
    }
    end_screen();
    return (has_won);
}
