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
    int type;
    position_t pos;
} object_t;

typedef struct map_s {
    char **map;
    object_t **boxes;
    object_t **goals;
    int nb_boxes;
    int nb_goals;
    int size_x;
    int size_y;
} map_t;

int my_strlen(char const *str);
void run_game(map_t *map);
void load_map(char const *filepath, map_t *map);
void check_inputs(int input, map_t *map, object_t *player);
void free_map(map_t *map);
void init_screen(void);
void end_screen(void);
object_t *create_object(int type, position_t pos);
object_t *create_player(map_t *map, int type);
void change_player_pos(object_t *player, map_t *map, position_t dir);
int move_boxes(object_t *player, map_t *map, position_t dir);
int is_same_pos(position_t pos1, position_t pos2);
int check_if_won(map_t *map);

#endif