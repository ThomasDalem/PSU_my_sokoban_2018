/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** Puts the 1d map into an 2d map
*/

void put_map1d_in_map2d(char const *map_1d, char **map_2d)
{
    int x = 0;
    int y = 0;

    for (int i = 0; map_1d[i] != '\0'; i++) {
        map_2d[y][x] = map_1d[i];
        x++;
        if (map_1d[i] == '\n') {
            map_2d[y][x] = '\0';
            x = 0;
            y++;
        }
    }
    map_2d[y][x] = '\0';
}