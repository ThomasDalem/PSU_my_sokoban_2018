/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** Initialize the screen at the beginning of the game
*/
#include <curses.h>
#include <ncurses.h>

void init_screen(void)
{
    initscr();
    attron(A_NORMAL);
    keypad(stdscr, true);
    noecho();
}

void end_screen(void)
{
    clear();
    endwin();
}