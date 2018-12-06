/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** Checks the arguments given by the user
*/
#include <unistd.h>
#include <stdlib.h>

void check_arguments(int ac)
{
    if (ac != 2) {
        write(1, "Invalid number of arguments\n", 28);
        exit(84);
    }
}