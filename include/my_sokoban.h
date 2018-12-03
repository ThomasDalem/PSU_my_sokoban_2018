/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** my_sokoban header file
*/

#ifndef __MY_SOKOBAN_H__
#define __MY_SOKOBAN_H__

typedef struct position_s {
    int x;
    int y;
} position_t;

typedef struct object_s {
    position_t pos;
} object_t;

void run_game(char **map);
char **load_map(char const *filepath);
void check_inputs(int input, char **map, object_t *player);
void free_map(char **map);
void init_screen(void);
void end_screen(void);
object_t *create_object(char **map);

#endif