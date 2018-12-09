/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** Tests the function to get differents sizes in a file
*/
#include <criterion/criterion.h>
#include "my_sokoban.h"

Test(sokoban, get_line_size)
{
    char map1d[41] = "#######\n#   P #\n#  X  #\n#   O #\n#######\n";
    char **map2d = NULL;
    map_t *map = malloc(sizeof(map_t));

    map2d = load_map_2d(map1d, map);
    cr_assert_eq(get_line_size(0, map1d), 7);
    for (int i = 0; i < 5; i++)
        free(map2d[i]);
    free(map);
}

Test(sokoban, get_number_of_lines)
{
    char map1d[41] = "#######\n#   P #\n#  X  #\n#   O #\n#######\n";
    char **map2d = NULL;
    map_t *map = malloc(sizeof(map_t));

    map2d = load_map_2d(map1d, map);
    cr_assert_eq(get_nb_lines(map1d), 6);
    for (int i = 0; i < 5; i++)
        free(map2d[i]);
    free(map);
}
