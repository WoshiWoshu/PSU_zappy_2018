/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** broadcast
*/

#include "broadcast.h"

#include <stdlib.h>

static void check_up(server_t *srv, const size_t p_idx, size_t idx, int *tile)
{
    if (srv->players[p_idx].pos->y > srv->players[idx].pos->y) {
        if (srv->players[p_idx].pos->x > srv->players[idx].pos->x) {
            srv->players[idx].dir == UP ? *tile = 6 : 0;
            srv->players[idx].dir == DOWN ? *tile = 2 : 0;
        } else if (srv->players[p_idx].pos->x < srv->players[idx].pos->x) {
            srv->players[idx].dir == UP ? *tile = 4 : 0;
            srv->players[idx].dir == DOWN ? *tile = 8 : 0;
        }
    } else if (srv->players[p_idx].pos->y < srv->players[idx].pos->y) {
        if (srv->players[p_idx].pos->x > srv->players[idx].pos->x) {
            srv->players[idx].dir == UP ? *tile = 8 : 0;
            srv->players[idx].dir == DOWN ? *tile = 4 : 0;
        } else if (srv->players[p_idx].pos->x < srv->players[idx].pos->x) {
            srv->players[idx].dir == UP ? *tile = 2 : 0;
            srv->players[idx].dir == DOWN ? *tile = 6 : 0;
        }
    }
}

static void check_down(server_t *srv, const size_t p_idx, size_t idx, int *tile)
{
    if (srv->players[p_idx].pos->y > srv->players[idx].pos->y) {
        if (srv->players[p_idx].pos->x > srv->players[idx].pos->x) {
            srv->players[idx].dir == RIGHT ? *tile = 8 : 0;
            srv->players[idx].dir == LEFT ? *tile = 4 : 0;
        } else if (srv->players[p_idx].pos->x < srv->players[idx].pos->x) {
            srv->players[idx].dir == RIGHT ? *tile = 6 : 0;
            srv->players[idx].dir == LEFT ? *tile = 2 : 0;
        }
    } else if (srv->players[p_idx].pos->y < srv->players[idx].pos->y) {
        if (srv->players[p_idx].pos->x > srv->players[idx].pos->x) {
            srv->players[idx].dir == RIGHT ? *tile = 2 : 0;
            srv->players[idx].dir == LEFT ? *tile = 6 : 0;
        } else if (srv->players[p_idx].pos->x < srv->players[idx].pos->x) {
            srv->players[idx].dir == RIGHT ? *tile = 4 : 0;
            srv->players[idx].dir == LEFT ? *tile = 8 : 0;
        }
    }
}

static void check_same(server_t *srv, const size_t p_idx, size_t idx, int *tile)
{
    if (srv->players[p_idx].pos->y == srv->players[idx].pos->y) {
        if (srv->players[p_idx].pos->x > srv->players[idx].pos->x) {
            srv->players[idx].dir == UP ? *tile = 7 : 0;
            srv->players[idx].dir == DOWN ? *tile = 3 : 0;
        } else if (srv->players[p_idx].pos->x < srv->players[idx].pos->x) {
            srv->players[idx].dir == UP ? *tile = 3 : 0;
            srv->players[idx].dir == DOWN ? *tile = 7 : 0;
        }
    } else if (srv->players[p_idx].pos->x == srv->players[idx].pos->x) {
        if (srv->players[p_idx].pos->y > srv->players[idx].pos->y) {
            srv->players[idx].dir == UP ? *tile = 5 : 0;
            srv->players[idx].dir == DOWN ? *tile = 1 : 0;
        } else if (srv->players[p_idx].pos->y < srv->players[idx].pos->y) {
            srv->players[idx].dir == UP ? *tile = 1 : 0;
            srv->players[idx].dir == DOWN ? *tile = 5 : 0;
        }
    }
}

static void check_sme2(server_t *srv, const size_t p_idx, size_t idx, int *tile)
{
    if (srv->players[p_idx].pos->y == srv->players[idx].pos->y) {
        if (srv->players[p_idx].pos->x > srv->players[idx].pos->x) {
            srv->players[idx].dir == RIGHT ? *tile = 1 : 0;
            srv->players[idx].dir == LEFT ? *tile = 5 : 0;
        } else if (srv->players[p_idx].pos->x < srv->players[idx].pos->x) {
            srv->players[idx].dir == RIGHT ? *tile = 5 : 0;
            srv->players[idx].dir == LEFT ? *tile = 1 : 0;
        }
    } else if (srv->players[p_idx].pos->x == srv->players[idx].pos->x) {
        if (srv->players[p_idx].pos->y > srv->players[idx].pos->y) {
            srv->players[idx].dir == RIGHT ? *tile = 7 : 0;
            srv->players[idx].dir == LEFT ? *tile = 3 : 0;
        } else if (srv->players[p_idx].pos->y < srv->players[idx].pos->y) {
            srv->players[idx].dir == RIGHT ? *tile = 3 : 0;
            srv->players[idx].dir == LEFT ? *tile = 7 : 0;
        }
    }
}

void start_broadcast(server_t *srv, const player_t *p, char *txt)
{
    char *msg = malloc(strlen(txt) + 15);
    int tile = 0;
    size_t p_idx = 0;

    for (p_idx = 0; srv->players[p_idx].sock != p->sock; p_idx++);
    for (size_t i = 0; i < srv->game_info.max_clients; ++i) {
        if (i == p_idx || srv->players[i].sock == 0)
            continue;
        check_up(srv, p_idx, i, &tile);
        check_down(srv, p_idx, i, &tile);
        check_same(srv, p_idx, i, &tile);
        check_sme2(srv, p_idx, i, &tile);
        if (srv->players[p_idx].pos->x == srv->players[i].pos->x
        && srv->players[p_idx].pos->y == srv->players[i].pos->y)
            tile = 0;
        sprintf(msg, "message %d, %s\n", tile, txt);
        write(srv->players[i].sock, msg, strlen(msg));
    }
    free(msg);
}