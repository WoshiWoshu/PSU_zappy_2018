/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** map
*/

#ifndef MAP_H_
#define MAP_H_

#include "player.h"
#include "player_lst.h"
#include "collectibles.h"

typedef struct tiles_s {
    player_lst_t *players;
    size_t stones[6];
    size_t food;
    coordinate_t coor;
} tiles_t;

typedef struct world_map_s {
    tiles_t **tiles;
    size_t height;
    size_t width;
} world_map_t;

void map_init(world_map_t *, size_t, size_t);
void display_tile(const tiles_t *);
void display_map(const world_map_t *);
void map_generate_collectibles(world_map_t *);

#endif /* !MAP_H_ */
