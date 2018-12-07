/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** Loads the map form a file
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my_sokoban.h"

void get_object(map_t *map, char const *line, int line_nb)
{
    int i = 0;
    position_t pos;

    pos.x = 0;
    pos.y = line_nb;
    while (line[i] != '\0' && line[i] != '\n') {
        if (line[i] == 'X') {
            pos.x = i;
            map->boxes[map->nb_boxes] = create_object(pos);
            map->nb_boxes++;
        }
        else if (line[i] == 'O') {
            pos.x = i;
            map->goals[map->nb_goals] = create_object(pos);
            map->nb_goals++;
        }
        i++;
    }
}

int get_biggest_line_size(char const *map)
{
    int biggest_line_size = 0;
    int line_size = 0;
    int i = 0;

    while (map[i] != '\0') {
        if (map[i] == '\n' && line_size > biggest_line_size)
            biggest_line_size = line_size;
        if (map[i] == '\n')
            line_size = 0;
        line_size++;
        i++;
    }
    return (biggest_line_size);
}

char *load_map_1d(char const *filepath)
{
    char *map = NULL;
    int file_size = 0;
    int fd = 0;

    file_size = get_file_size(filepath);
    map = malloc(sizeof(char) * (file_size + 1));
    check_malloc(map);
    fd = open(filepath, O_RDONLY);
    read(fd, map, file_size);
    map[file_size] = '\0';
    close(fd);
    return (map);
}

char **load_map_2d(char const *map_1d, map_t *map)
{
    char **map_2d;
    int x = 0;
    int y = 0;

    map->size_y = get_nb_lines(map_1d);
    map->size_x = get_biggest_line_size(map_1d);
    map_2d = malloc(sizeof(char *) * map->size_y);
    check_malloc(map_2d);
    for (int i = 0; i < map->size_y; i++) {
        map_2d[i] = malloc(sizeof(char) * (map->size_x + 1));
        check_malloc(map_2d[i]);
    }
    put_map1d_in_map2d(map_1d, map_2d);
    return (map_2d);
}

char **load_map(char const *filepath, map_t *map)
{
    char *map_1d = NULL;
    char **map_2d = NULL;

    map_1d = load_map_1d(filepath);
    map_2d = load_map_2d(map_1d, map);
    for (int i = 0; i < map->size_y; i++)
        get_object(map, map_2d[i], i);
    free(map_1d);
    return (map_2d);
}
