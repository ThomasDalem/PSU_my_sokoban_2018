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
    while (line[i] != '\0') {
        if (line[i] == 'X') {
            pos.x = i;
            map->boxes[map->nb_boxes] = create_object(2, pos);
            map->nb_boxes++;
        }
        else if (line[i] == 'O') {
            pos.x = i;
            map->goals[map->nb_goals] = create_object(3, pos);
            map->nb_goals++;
        }
        i++;
    }
}

void load_map(char const *filepath, map_t *map)
{
    FILE *f = fopen(filepath, "r");
    char **char_map = NULL;
    size_t size = 0;
    ssize_t line_size = 0;

    if (f == NULL) {
        write(1, "Cannot open the file\n", 21);
        exit(84);
    }
    char_map = malloc(sizeof(char *) * 100);
    if (map == NULL)
        exit(84);
    for (int i = 0; line_size != -1; i++) {
        line_size = getline(&char_map[i], &size, f);
        get_object(map, char_map[i], i);
        map->size_y = i;
    }
    map->size_x = my_strlen(char_map[1]);
    fclose(f);
    map->map = char_map;
}
