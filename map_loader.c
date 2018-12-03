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

char **load_map(char const *filepath)
{
    FILE *f = fopen(filepath, "r");
    char **map = NULL;
    size_t size = 0;
    ssize_t line_size = 0;

    if (f == NULL) {
        write(1, "Cannot open the file\n", 21);
        exit(84);
    }
    map = malloc(sizeof(char *) * 96);
    if (map == NULL)
        exit(84);
    for (int i = 0; line_size != -1; i++)
        line_size = getline(&map[i], &size, f);
    fclose(f);
    return (map);
}
