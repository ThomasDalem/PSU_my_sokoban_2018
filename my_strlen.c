/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** Returns the lenght of a string
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}
