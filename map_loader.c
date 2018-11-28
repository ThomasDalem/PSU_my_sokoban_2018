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
#include <unistd.h>

char *load_file_in_buffer(char const *filepath, int fd)
{
    struct stat sb;
    int line_size = 0;
    int size = 0;
    char *buffer;

    if (stat(filepath, &sb))
        exit(84);
    buffer = malloc(sizeof(char) * sb.st_size);
    if (buffer == NULL)
        exit(84);
    size = read(fd, buffer, sb.st_size);
    return (buffer);
}

int get_number_of_lines(char const *buffer)
{
    int i = 0;
    int nb_of_lines = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == '\n')
            nb_of_lines++;
        i++;
    }
    return (nb_of_lines);
}

int get_number_of_cols(char const *buffer)
{
    int i = 0;

    while (buffer[i] != '\n')
        i++;
    return (i);
}

char **put_buffer_in_map(char **map, char *buffer, int nb_rows, int nb_cols)
{
    int z = 0;

    for (int i = 0; i < nb_rows; i++) {
        for (int y = 0; y < nb_cols; y++) {
            map[i][y] = buffer[z];
            z++;
        }
    }
}

char **load_map(char const *filepath)
{
    char **map;
    char *buffer;
    int buffer_size = 0;
    int cols = 0;
    int rows = 0;
    int fd = 0;

    fd = open(filepath, O_RDONLY);
    if (fd <= 0) {
        write(1, "Can't open file\n", 16);
        exit(84);
    }
    buffer = load_file_in_buffer(filepath, fd);
    rows = get_number_of_lines(buffer);
    cols = get_number_of_cols(buffer);
    map = malloc(sizeof(char *) * rows);
    for (int i = 0; i < rows; i++)
        map[i] = malloc(sizeof(char) * cols + 1);
    put_buffer_in_map(map, buffer, rows, cols);
    free(buffer);
    return(map);
}
