/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** my_sokoban header file
*/

#ifndef __MY_SOKOBAN_H__
#define __MY_SOKOBAN_H__

typedef struct position {
    int x;
    int y;
} position_t;

void run_game(char const *filepath);
char **load_map(char const *filepath);

#endif