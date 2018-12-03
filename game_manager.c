/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** Functions to manage the game
*/
#include <curses.h>
#include <ncurses.h>
#include <unistd.h>
#include "my_sokoban.h"

void run_game(char **map)
{
    int input = 0;
    int i = 0;
    object_t *player = create_object(map);

    init_screen();
    while (input != ' ') {
        i++;
        for (int i = 0; i < 10; i++)
            mvprintw(LINES / 2 - 5 + i, COLS / 2 - 5, map[i]);
        input = getch();
        check_inputs(input, map, player);            
        refresh();
    }
    end_screen();
}
