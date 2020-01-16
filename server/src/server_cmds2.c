/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** server_cmds2
*/

#include "server_cmds2.h"

#include "movement.h"

void write_eject(world_map_t *map, player_t *p)
{
    player_lst_t *list = map->tiles[p->pos->y][p->pos->x].players;
    size_t nb = 0;

    while (list) {
        if (list->player->sock != p->sock) {
            move_forward(map, list->player);
            write(list->player->sock, "eject: 5\n", 9);
            ++nb;
        }
        list = list->next;
    }
    if (nb == 0)
        write(p->sock, "ko\n", 3);
    else
        write(p->sock, "ok\n", 3);
}