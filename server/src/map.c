/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** map
*/

#include "map.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void map_init(world_map_t *map, size_t height, size_t width)
{
    memset(map, 0, sizeof(world_map_t));
    map->tiles = calloc(height, sizeof(tiles_t));
    map->height = height;
    map->width = width;
    for (size_t i = 0; i < height; i++) {
        map->tiles[i] = calloc(width, sizeof(tiles_t));
    }
    for (size_t y = 0; y < height; y++) {
        for (size_t x = 0; x < width; x++) {
            map->tiles[y][x].players = NULL;
            map->tiles[y][x].coor.x = x;
            map->tiles[y][x].coor.y = y;
        }
    }
    map_generate_collectibles(map);
}

void display_tile(const tiles_t *tile)
{
    printf("tile (y:%ld, x:%ld), food: %ld, stones: [%ld, %ld, %ld, %ld, %ld,"
    " %ld]\n", tile->coor.y, tile->coor.x, tile->food, tile->stones[0],
    tile->stones[1], tile->stones[2], tile->stones[3], tile->stones[4],
    tile->stones[5]);
    player_lst_display(tile->players);
}

void display_map(const world_map_t *map)
{
    for (size_t y = 0; y < map->height; y++) {
        for (size_t x = 0; x < map->width; x++) {
            display_tile(&map->tiles[y][x]);
        }
    }
}

void map_generate_collectibles(world_map_t *map)
{
    int sr = rand() % 39;

    for (size_t y = 0; y < map->height; y++) {
        for (size_t x = 0; x < map->width; x++) {
            if (rand() % 2 == 0)
                map->tiles[y][x].food++;
            if (rand() % 2 == 0) {
                sr = rand() % 39;
                sr >= 0 && sr <= 8 ? map->tiles[y][x].stones[LINEMATE]++ : 0;
                sr >= 9 && sr <= 16 ? map->tiles[y][x].stones[DERAUMERE]++ : 0;
                sr >= 17 && sr <= 26 ? map->tiles[y][x].stones[SIBUR]++ : 0;
                sr >= 27 && sr <= 31 ? map->tiles[y][x].stones[MENDIANE]++ : 0;
                sr >= 32 && sr <= 37 ? map->tiles[y][x].stones[PHIRAS]++ : 0;
                sr >= 38 && sr <= 38 ? map->tiles[y][x].stones[THYSTAME]++ : 0;
            }
        }
    }
}