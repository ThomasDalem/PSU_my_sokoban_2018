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
int run_game(map_t *map, int *restart);
char **load_map(char const *filepath, map_t *map);
void check_inputs(int input, map_t *map, object_t *player, int *restart);
void free_map(map_t *map);
void init_screen(void);
void end_screen(void);
object_t *create_object(position_t pos);
object_t *create_player(map_t *map);
void change_player_pos(object_t *player, map_t *map, position_t dir);
int move_boxes(object_t *player, map_t *map, position_t dir);
int is_same_pos(position_t pos1, position_t pos2);
int check_if_won(map_t *map);
void display_goals(map_t *map, object_t *player);
int check_if_stuck(map_t *map);
int can_move(char new_pos);
int can_move_up(object_t *box, char **map);
int can_move_down(object_t *box, char **map);
int can_move_left(object_t *box, char **map);
int can_move_right(object_t *box, char **map);
void my_put_nbr(int nb);
int get_file_size(char const *filepath);
int get_line_size(int start, char const *map);
int get_nb_lines(char const *map);
void check_malloc(void *ptr);
void check_arguments(int ac, char **av);
void put_map1d_in_map2d(char const *map1d, char **map2d);
void check_map(char *map);
char **load_map_2d(char const *map_1d, map_t *map);
void get_object(map_t *map, char const *line, int line_nb);
int get_biggest_line_size(char const *map);

#endif