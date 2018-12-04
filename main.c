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
    map_t *map = malloc(sizeof(map_t));
    int has_won = 0;
    int restart = 1;

    if (ac != 2) {
        write(1, "Invalid number of arguments\n", 28);
        return (84);
    }
    init_screen();
    while (restart == 1) {
        restart = 0;
        map->nb_boxes = 0;
        map->nb_goals = 0;
        map->boxes = malloc(sizeof(object_t *) * 30);
        map->goals = malloc(sizeof(object_t *) * 30);
        load_map(av[1], map);
        has_won = run_game(map, &restart);
        my_put_nbr(has_won);
        clear();
    }
    free_map(map);
    end_screen();
    return (0);
}
