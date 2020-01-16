/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** server_cmds1
*/

#include "server_cmds1.h"

#include <stdlib.h>

#include "look.h"
#include "interaction.h"
#include "elevation.h"

int connect_nbr(server_t *srv, char *team)
{
    int nb = srv->game_info.nb_clients;

    for (size_t i = 0; i < srv->game_info.max_clients; ++i) {
        if (srv->players[i].team == NULL)
            continue;
        if (!strcmp(srv->players[i].team, team))
            --nb;
    }
    return (nb);
}

void write_look(const world_map_t *map, player_t *p)
{
    char *look = malloc(1000 * p->level);

    memset(look, 0, 1000 * p->level);
    look = get_look(map, p, look);
    write(p->sock, look, strlen(look));
    free(look);
}

void write_take(world_map_t *map, player_t *p, char *obj)
{
    char *take = malloc(4);

    memset(take, 0, 4);
    strcpy(take, "ko\n");
    if (!strncmp(obj, "food", 4))
        take = take_food(map, p, take);
    if (!strncmp(obj, "linemate", 8))
        take = take_stone(map, p, LINEMATE, take);
    if (!strncmp(obj, "deraumere", 9))
        take = take_stone(map, p, DERAUMERE, take);
    if (!strncmp(obj, "sibur", 5))
        take = take_stone(map, p, SIBUR, take);
    if (!strncmp(obj, "mendiane", 8))
        take = take_stone(map, p, MENDIANE, take);
    if (!strncmp(obj, "phiras", 6))
        take = take_stone(map, p, PHIRAS, take);
    if (!strncmp(obj, "thystame", 8))
        take = take_stone(map, p, THYSTAME, take);
    write(p->sock, take, strlen(take));
    free(take);
}

void write_drop(world_map_t *map, player_t *p, char *obj)
{
    char *drop = malloc(4);

    memset(drop, 0, 4);
    strcpy(drop, "ko\n");
    if (!strncmp(obj, "food", 4))
        drop = drop_food(map, p, drop);
    if (!strncmp(obj, "linemate", 8))
        drop = drop_stone(map, p, LINEMATE, drop);
    if (!strncmp(obj, "deraumere", 9))
        drop = drop_stone(map, p, DERAUMERE, drop);
    if (!strncmp(obj, "sibur", 5))
        drop = drop_stone(map, p, SIBUR, drop);
    if (!strncmp(obj, "mendiane", 8))
        drop = drop_stone(map, p, MENDIANE, drop);
    if (!strncmp(obj, "phiras", 6))
        drop = drop_stone(map, p, PHIRAS, drop);
    if (!strncmp(obj, "thystame", 8))
        drop = drop_stone(map, p, THYSTAME, drop);
    write(p->sock, drop, strlen(drop));
    free(drop);
}

void write_incantation(world_map_t *map, player_t *p)
{
    char *lvl = malloc(40);

    memset(lvl, 0, 40);
    lvl = start_elevation(map, p, lvl);
    write(p->sock, lvl, strlen(lvl));
    free(lvl);
}