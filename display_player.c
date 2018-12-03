/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** Displays the player on the map
*/
#include "my_sokoban.h"

void change_player_pos(object_t *player, map_t *map, position_t dir)
{
    if (map->map[player->pos.y + dir.y][player->pos.x + dir.x] != '#') {
        map->map[player->pos.y + dir.y][player->pos.x + dir.x] = 'P';
        map->map[player->pos.y][player->pos.x] = ' ';
        player->pos.y += dir.y;
        player->pos.x += dir.x;
    }
}