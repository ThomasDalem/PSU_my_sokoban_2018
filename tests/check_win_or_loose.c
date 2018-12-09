/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** Tests the win or loose conditions
*/
#include <criterion/criterion.h>
#include "my_sokoban.h"

Test(sokoban, check_win)
{
    char map1d[41] = "#######\n#   P #\n#     #\n#   X #\n#######\n";
    char **map2d = NULL;
    map_t *map = malloc(sizeof(map_t));

    map->map = load_map_2d(map1d, map);
    map->nb_boxes = 1;
    map->nb_goals = 1;
    map->goals = malloc(sizeof(object_t *) * 1);
    map->boxes = malloc(sizeof(object_t *) * 1);
    map->goals[0] = malloc(sizeof(object_t));
    map->boxes[0] = malloc(sizeof(object_t));
    map->goals[0]->pos.x = 3;
    map->goals[0]->pos.y = 3;
    map->boxes[0]->pos.x = 3;
    map->boxes[0]->pos.y = 3;
    cr_assert_eq(check_if_won(map), 0);
    for (int i = 0; i < 5; i++)
        free(map->map[i]);
    free(map->boxes);
    free(map->goals);
}

Test(sokoban, check_not_win)
{
    char map1d[41] = "#######\n#   P #\n#     #\n#   X #\n#######\n";
    char **map2d = NULL;
    map_t *map = malloc(sizeof(map_t));

    map->map = load_map_2d(map1d, map);
    map->nb_boxes = 1;
    map->nb_goals = 1;
    map->goals = malloc(sizeof(object_t *) * 1);
    map->boxes = malloc(sizeof(object_t *) * 1);
    map->goals[0] = malloc(sizeof(object_t));
    map->boxes[0] = malloc(sizeof(object_t));
    map->goals[0]->pos.x = 3;
    map->goals[0]->pos.y = 4;
    map->boxes[0]->pos.x = 3;
    map->boxes[0]->pos.y = 3;
    cr_assert_eq(check_if_won(map), 1);
    for (int i = 0; i < 5; i++)
        free(map->map[i]);
    free(map->boxes);
    free(map->goals);
}

Test(sokoban, check_loose)
{
    char map1d[41] = "#######\n#   P #\n#     #\n# O  X#\n#######\n";
    char **map2d = NULL;
    map_t *map = malloc(sizeof(map_t));

    map->map = load_map_2d(map1d, map);
    map->nb_boxes = 1;
    map->boxes = malloc(sizeof(object_t *) * 1);
    map->boxes[0] = malloc(sizeof(object_t));
    map->boxes[0]->pos.x = 5;
    map->boxes[0]->pos.y = 4;
    cr_assert_eq(check_if_stuck(map), 1);
    for (int i = 0; i < 5; i++)
        free(map->map[i]);
    free(map->boxes);
}


Test(sokoban, check_not_loose)
{
    char map1d[41] = "#######\n#   P #\n#     #\n# O  X#\n#######\n";
    char **map2d = NULL;
    map_t *map = malloc(sizeof(map_t));

    map->map = load_map_2d(map1d, map);
    map->nb_boxes = 1;
    map->boxes = malloc(sizeof(object_t *) * 1);
    map->boxes[0] = malloc(sizeof(object_t));
    map->boxes[0]->pos.x = 3;
    map->boxes[0]->pos.y = 3;
    cr_assert_eq(check_if_stuck(map), 0);
    for (int i = 0; i < 5; i++)
        free(map->map[i]);
    free(map->boxes);
}
