/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** Displays the goals if there are no boxes or player on them
*/
#include "my_sokoban.h"

void display_goal(map_t *map ,object_t *goal, object_t *player)
{
    position_t goal_pos = goal->pos;
    position_t box_pos;

    if (is_same_pos(goal_pos, player->pos) == 1)
        return;
    for (int i = 0; i < map->nb_boxes; i++) {
         box_pos = map->boxes[i]->pos;
        if (is_same_pos(goal_pos, box_pos) == 1)
            return;
    }
    map->map[goal->pos.y][goal->pos.x] = 'O';
}

void display_goals(map_t *map, object_t *player)
{
    for (int i = 0; i < map->nb_goals; i++)
        display_goal(map, map->goals[i], player);
}