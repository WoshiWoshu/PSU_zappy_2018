/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** server_cmds1
*/

#ifndef SERVER_CMDS1_H_
#define SERVER_CMDS1_H_

#include "server.h"
#include "map.h"

int connect_nbr(server_t *, char *);
void write_look(const world_map_t *, player_t *);
void write_take(world_map_t *, player_t *, char *);
void write_drop(world_map_t *, player_t *, char *);
void write_incantation(world_map_t *, player_t *);

#endif /* !SERVER_CMDS1_H_ */
