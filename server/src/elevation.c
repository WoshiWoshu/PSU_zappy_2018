/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** elevation
*/

#include "elevation.h"

#include <stdio.h>

static bool check_tile4(tiles_t *tile, player_t *player)
{
    if (player->level == 7 && tile->stones[LINEMATE] >= 2
    && tile->stones[DERAUMERE] >= 2 && tile->stones[SIBUR] >= 2
    && tile->stones[MENDIANE] >= 2 && tile->stones[PHIRAS] >= 2
    && tile->stones[THYSTAME] >= 1) {
        tile->stones[LINEMATE] -= 2;
        tile->stones[DERAUMERE] -= 2;
        tile->stones[SIBUR] -= 2;
        tile->stones[MENDIANE] -= 2;
        tile->stones[PHIRAS] -= 2;
        tile->stones[THYSTAME]--;
        return (true);
    }
    return (false);
}

static bool check_tile3(tiles_t *tile, player_t *player)
{
    if (player->level == 6 && tile->stones[0] >= 1 && tile->stones[1] >= 2
    && tile->stones[SIBUR] >= 3 && tile->stones[PHIRAS] >= 1) {
        tile->stones[LINEMATE]--;
        tile->stones[DERAUMERE] -= 2;
        tile->stones[SIBUR] -= 3;
        tile->stones[PHIRAS]--;
        return (true);
    }
    return (check_tile4(tile, player));
}

static bool check_tile2(tiles_t *tile, player_t *player)
{
    if (player->level == 4 && tile->stones[LINEMATE] >= 1
    && tile->stones[DERAUMERE] >= 1 && tile->stones[SIBUR] >= 2
    && tile->stones[PHIRAS] >= 1) {
        tile->stones[LINEMATE]--;
        tile->stones[DERAUMERE]--;
        tile->stones[SIBUR] -= 2;
        tile->stones[PHIRAS]--;
        return (true);
    }
    if (player->level == 5 && tile->stones[LINEMATE] >= 1
    && tile->stones[DERAUMERE] >= 2 && tile->stones[SIBUR] >= 1
    && tile->stones[MENDIANE] >= 3) {
        tile->stones[LINEMATE]--;
        tile->stones[DERAUMERE] -= 2;
        tile->stones[SIBUR]--;
        tile->stones[MENDIANE] -= 3;
        return (true);
    }
    return (check_tile3(tile, player));
}

static bool check_tile(tiles_t *tile, player_t *player)
{
    if (player->level == 1 && tile->stones[LINEMATE] >= 1) {
        tile->stones[LINEMATE]--;
        return (true);
    }
    if (player->level == 2 && tile->stones[LINEMATE] >= 1
    && tile->stones[DERAUMERE] >= 1 && tile->stones[SIBUR] >= 1) {
        tile->stones[LINEMATE]--;
        tile->stones[DERAUMERE]--;
        tile->stones[SIBUR]--;
        return (true);
    }
    if (player->level == 3 && tile->stones[LINEMATE] >= 2
    && tile->stones[SIBUR] >= 1 && tile->stones[PHIRAS] >= 2) {
        tile->stones[LINEMATE] -= 2;
        tile->stones[SIBUR]--;
        tile->stones[PHIRAS] -= 2;
        return (true);
    }
    return (check_tile2(tile, player));
}

char *start_elevation(world_map_t *map, player_t *p, char *msg)
{
    player_lst_t *current = map->tiles[p->pos->y][p->pos->x].players;
    size_t lvl = p->level;

    if (check_players(map->tiles[p->pos->y][p->pos->x].players, p)
    && check_tile(&map->tiles[p->pos->y][p->pos->x], p)) {
        while (current != NULL) {
            current->player->level == lvl ? current->player->level++ : 0;
            current = current->next;
        }
        sprintf(msg, "Elevation underway Current level: %ld\n", p->level);
        return (msg);
    }
    sprintf(msg, "ko\n");
    return (msg);
}