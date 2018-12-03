/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** Functions to move the boxes on the map
*/
#include "my_sokoban.h"

int is_same_pos(position_t pos1, position_t pos2)
{
    if (pos1.x == pos2.x && pos1.y == pos2.y)
        return (1);
    return (0);
}

int can_move(char new_pos)
{
    if (new_pos != '#' && new_pos != 'X')
        return (1);
    return (0);
}

int move_boxes(object_t *player, map_t *map, position_t dir)
{
    position_t player_pos;
    position_t box_pos;
    char new_pos;
    player_pos.x = player->pos.x + dir.x;
    player_pos.y = player->pos.y + dir.y;
    box_pos.x = 0;
    box_pos.y = 0;

    for (int i = 0; i < map->nb_objects; i++) {
        box_pos.x = map->objects[i]->pos.x;
        box_pos.y = map->objects[i]->pos.y;
        new_pos = map->map[box_pos.y + dir.y][box_pos.x + dir.x];
        if (is_same_pos(player_pos, box_pos) && can_move(new_pos)){
            map->objects[i]->pos.x += dir.x;
            map->objects[i]->pos.y += dir.y;
            map->map[box_pos.y + dir.y][box_pos.x + dir.x] = 'X';
        }
        else if (is_same_pos(player_pos, box_pos) && can_move(new_pos) != 1)
            return(-1);
    }
    return (1);
}
