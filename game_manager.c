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

void display_map(char **map)
{
    for (int i = 0; i < 8; i++) {
        write(1, map[i], 10);
    }
}

void run_game(char const *filepath)
{
    char **map;

    map = load_map(filepath);
    display_map(map);
    /*
    WINDOW *win;
    int end_game = 0;
    position_t pos;
    int input = 0;
    char *buffer = load_map(filepath);

    initscr();
    attron(A_NORMAL);
    while (input != ' ') {
        refresh();
        clear();
        mvprintw(LINES / 2, COLS / 2, buffer);        
        input = getch();
        end_game = 1;
    }
    clear();
    endwin();
    */
}
