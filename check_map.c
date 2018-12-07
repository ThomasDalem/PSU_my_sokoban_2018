/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** Checks if the map contains only allowed characters
*/
#include <curses.h>
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_sokoban.h"

void check_map(char *map)
{
    int i = 0;

    while (map[i] != '\0') {
        if (map[i] == '#' || map[i] == 'P' || map[i] == 'O' || map[i] == 'X')
            i++;
        else if (map[i] == '\n' || map[i] == ' ')
            i++;
        else {
            free(map);
            clear();
            end_screen();
            write(1, "Invalid map\n", 12);
            exit(84);
        }
    }
}