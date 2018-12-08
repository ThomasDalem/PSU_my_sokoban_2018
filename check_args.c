/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** Checks the arguments given by the user
*/
#include <unistd.h>
#include <stdlib.h>

void check_arguments(int ac, char **av)
{
    if (ac != 2) {
        write(1, "Invalid number of arguments\n", 28);
        exit(84);
    }
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        write(1, "USAGE\n     ./my_sokoban\n", 24);
        write(1, "DESCRIPTION\n     ", 17);
        write(1, "map  file representing the warehouse map, containing ", 53);
        write(1, "‘#’ for walls,\n     ", 24);
        write(1, "‘P’ for the player, ‘X’ for boxes and ‘O’ ", 42);
        write(1, "for storage locations.\n", 23);
        exit(0);
    }
}