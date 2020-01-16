/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** movement
*/

#include "movement.h"

void turn_right(player_t *player)
{
    switch (player->dir) {
        case UP:
            player->dir = RIGHT;
            break;
        case DOWN:
            player->dir = LEFT;
            break;
        case RIGHT:
            player->dir = DOWN;
            break;
        case LEFT:
            player->dir = UP;
            break;
    }
}

void turn_left(player_t *player)
{
    switch (player->dir) {
        case UP:
            player->dir = LEFT;
            break;
        case DOWN:
            player->dir = RIGHT;
            break;
        case RIGHT:
            player->dir = UP;
            break;
        case LEFT:
            player->dir = DOWN;
            break;
    }
}

void move_forward(world_map_t *map, player_t *play)
{
    size_t lim_x = map->width - 1;
    size_t lim_y = map->height - 1;

    player_lst_pop(&map->tiles[play->pos->y][play->pos->x].players, play);
    switch (play->dir) {
        case UP:
            play->pos->y == 0 ? play->pos->y = lim_y : play->pos->y--;
            break;
        case DOWN:
            play->pos->y == lim_y ? play->pos->y = 0 : play->pos->y++;
            break;
        case RIGHT:
            play->pos->x == lim_x ? play->pos->x = 0 : play->pos->x++;
            break;
        case LEFT:
            play->pos->x == 0 ? play->pos->x = lim_x : play->pos->x--;
            break;
    }
    player_lst_push(&map->tiles[play->pos->y][play->pos->x].players, play);
}