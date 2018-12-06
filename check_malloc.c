/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** Checks if the malloc worked
*/
#include <unistd.h>
#include <stdlib.h>

void check_malloc(void *ptr)
{
    if (ptr == NULL) {
        write(1, "Error : malloc\n", 15);
        exit(84);
    }
}
