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
    if (ac != 2) {
        write(1, "Enter a valid number of arguments\n", 34);
        return (84);
    }
    //load_map(av[1]);
    run_game(av[1]);   
}
