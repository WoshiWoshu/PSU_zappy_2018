/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** collectibles
*/

#include "interaction.h"

#include <string.h>
#include <stdio.h>

char *take_stone(world_map_t *map, player_t *player, stones_t stone, char *msg)
{
    if (map->tiles[player->pos->y][player->pos->x].stones[stone] > 0) {
        map->tiles[player->pos->y][player->pos->x].stones[stone]--;
        player->stones[stone]++;
        strcpy(msg, "ok\n");
    } else
        strcpy(msg, "ko\n");
    return (msg);
}

char *drop_stone(world_map_t *map, player_t *player, stones_t stone, char *msg)
{
    if (player->stones[stone] > 0) {
        player->stones[stone]--;
        map->tiles[player->pos->y][player->pos->x].stones[stone]++;
        strcpy(msg, "ok\n");
    } else
        strcpy(msg, "ko\n");
    return (msg);
}

char *take_food(world_map_t *map, player_t *player, char *msg)
{
    if (map->tiles[player->pos->y][player->pos->x].food > 0) {
        map->tiles[player->pos->y][player->pos->x].food--;
        player->food++;
        strcpy(msg, "ok\n");
    } else
        strcpy(msg, "ko\n");
    return (msg);
}

char *drop_food(world_map_t *map, player_t *player, char *msg)
{
    if (player->food > 0) {
        player->food--;
        map->tiles[player->pos->y][player->pos->x].food++;
        strcpy(msg, "ok\n");
    } else
        strcpy(msg, "ko\n");
    return (msg);
}

char *get_inventory(const player_t *player, char *inventory)
{
    sprintf(inventory, "[food %ld, linemate %ld, dera"
    "umere %ld, sibur %ld, mendiane %ld, phiras %ld, thystame %ld]\n",
    player->food, player->stones[LINEMATE], player->stones[DERAUMERE],
    player->stones[SIBUR], player->stones[MENDIANE], player->stones[PHIRAS],
    player->stones[THYSTAME]);
    return (inventory);
}