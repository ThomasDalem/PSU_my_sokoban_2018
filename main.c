/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** main function for the my_sokoban program
*/
#include <unistd.h>
#include "my_sokoban.h"

int main (int ac, char **av)
{
    char **map = NULL;

    if (ac != 2) {
        write(1, "Invalid number of arguments\n", 28);
        return (84);
    }
    map = load_map(av[1]);
    run_game(map);
    free_map(map);   
}
