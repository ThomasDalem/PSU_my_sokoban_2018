/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** Tests the map loading functions
*/
#include <criterion/criterion.h>
#include <stdlib.h>
#include "my_sokoban.h"

Test(sokoban, load_map)
{
    char map1d[41] = "#######\n#   P #\n#  X  #\n#   O #\n#######\n";
    char **map2d = NULL;
    map_t *map = malloc(sizeof(map_t));

    map2d = load_map_2d(map1d, map);
    cr_assert_str_eq(map2d[0], "#######\n");
    cr_assert_str_eq(map2d[1], "#   P #\n");
    cr_assert_str_eq(map2d[2], "#  X  #\n");
    cr_assert_str_eq(map2d[3], "#   O #\n");
    cr_assert_str_eq(map2d[4], "#######\n");
    free(map);
    for (int i = 0; i < 5; i++)
        free(map2d[i]);
}

Test(sokoban, get_player_pos)
{
    char map1d[41] = "#######\n#   P #\n#  X  #\n#   O #\n#######\n";
    char **map2d = NULL;
    map_t *map = malloc(sizeof(map_t));
    object_t *player = NULL;

    map->map = load_map_2d(map1d, map);
    player = create_player(map);
    cr_assert_eq(player->pos.x, 4);
    cr_assert_eq(player->pos.y, 1);
    free(player);
    for (int i = 0; i < 5; i++)
        free(map->map[i]);
    free(map);
}

Test(sokoban, get_biggest_line_size)
{
    char map1d[44] = "#######\n#   P #\n#  X  #\n#   O #\n##########\n";
    char **map2d = NULL;
    map_t *map = malloc(sizeof(map_t));

    map->map = load_map_2d(map1d, map);
    cr_assert_eq(get_biggest_line_size(map1d), 11);
    for (int i = 0; i < 5; i++)
        free(map->map[i]);
    free(map);
}
