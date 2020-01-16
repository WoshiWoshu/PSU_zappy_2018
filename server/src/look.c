/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** look
*/

#include "look.h"

#include <string.h>

#include "help.h"

static char *get_look3(const world_map_t *map, const player_t *p, char *msg)
{
    if (p->dir == LEFT) {
        for (size_t x = 1; x <= p->level; x++) {
            for (size_t y = x; y >= 1; y--)
                add_tile_to_msg(&map->tiles[(p->pos->y + y) % map->height]
                [(p->pos->x - x) % map->width], msg);
            add_tile_to_msg(&map->tiles[p->pos->y]
            [(p->pos->x - x) % map->width], msg);
            for (size_t y = 1; y <= x; y++)
                add_tile_to_msg(&map->tiles[(p->pos->y - y) % map->height]
                [(p->pos->x - x) % map->width], msg);
        }
    }
    msg[strlen(msg) - 1] = 0;
    memmove(&msg[1], &msg[1 + 1], strlen(msg) - 1);
    strcat(msg, "]\n");
    return (clean_look(msg));
}

static char *get_look2(const world_map_t *map, const player_t *p, char *msg)
{
    if (p->dir == RIGHT) {
        for (size_t x = 1; x <= p->level; x++) {
            for (size_t y = x; y >= 1; y--)
                add_tile_to_msg(&map->tiles[(p->pos->y - y) % map->height]
                [(p->pos->x + x) % map->width], msg);
            add_tile_to_msg(&map->tiles[p->pos->y]
            [(p->pos->x + x) % map->width], msg);
            for (size_t y = 1; y <= x; y++)
                add_tile_to_msg(&map->tiles[(p->pos->y + y) % map->height]
                [(p->pos->x + x) % map->width], msg);
        }
    }
    return (get_look3(map, p, msg));
}

static char *get_look1(const world_map_t *map, const player_t *p, char *msg)
{
    if (p->dir == DOWN) {
        for (size_t y = 1; y <= p->level; y++) {
            for (size_t x = y; x >= 1; x--)
                add_tile_to_msg(&map->tiles[(p->pos->y + y) % map->height]
                [(p->pos->x + x) % map->width], msg);
            add_tile_to_msg(&map->tiles[(p->pos->y + y) % map->height]
            [p->pos->x], msg);
            for (size_t x = 1; x <= y; x++)
                add_tile_to_msg(&map->tiles[(p->pos->y + y) % map->height]
                [(p->pos->x - x) % map->width], msg);
        }
    }
    return (get_look2(map, p, msg));
}

char *get_look(const world_map_t *map, const player_t *player, char *msg)
{
    strcpy(msg, "[");
    add_tile_to_msg(&map->tiles[player->pos->y][player->pos->x], msg);
    if (player->dir == UP) {
        for (size_t y = 1; y <= player->level; y++) {
            for (size_t x = y; x >= 1; x--)
                add_tile_to_msg(&map->tiles[(player->pos->y - y) % map->height]
                [(player->pos->x - x) % map->width], msg);
            add_tile_to_msg(&map->tiles[(player->pos->y - y) % map->height]
            [player->pos->x], msg);
            for (size_t x = 1; x <= y; x++)
                add_tile_to_msg(&map->tiles[(player->pos->y - y) % map->height]
                [(player->pos->x + x) % map->width], msg);
        }
    }
    return (get_look1(map, player, msg));
}