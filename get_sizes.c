/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** Functions to get the sizes of files or lines
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <ncurses.h>
#include <curses.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_sokoban.h"

int get_file_size(char const *filepath)
{
    struct stat sb;
    int file_size = 0;

    if (stat(filepath, &sb) == -1) {
        clear();
        end_screen();
        write(1, "Error : Can't get file size\n", 28);
        exit(84);
    }
    file_size = sb.st_size;
    return (file_size);
}

int get_nb_lines(char const *map)
{
    int i = 0;
    int nb_lines = 0;

    while (map[i] != '\0') {
        if (map[i] == '\n')
            nb_lines++;
        i++;
    }
    nb_lines++;
    return (nb_lines);
}

int get_line_size(int start, char const *map)
{
    int i = 0;

    while (map[start + i] != '\n')
        i++;
    return (i);
}