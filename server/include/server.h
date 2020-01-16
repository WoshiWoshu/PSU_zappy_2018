/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** server
*/

#ifndef SERVER_H_
#define SERVER_H_

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/select.h>

#include "player.h"
#include "map.h"

typedef struct game_info_s {
    size_t width;
    size_t height;
    char **teams;
    size_t nb_clients;
    size_t freq;
    size_t max_clients;
} game_info_t;

typedef struct server_s {
    size_t port;
    game_info_t game_info;
    struct sockaddr_in srv;
    int sock;
    socklen_t size;
    int max_cli_sock;
    int cur_cli_sock;
    fd_set fd;
    player_t *players;
    world_map_t *map;
} server_t;

void start_server(server_t *);

#endif /* !SERVER_H_ */
