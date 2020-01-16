/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** server
*/

#include "server.h"

#include "server_util.h"
#include "server_cmds.h"

static void connection(server_t *srv)
{
    int sk = accept(srv->sock, (struct sockaddr *)&srv->srv, &srv->size);

    if (sk < 0)
        print_error("accept error", srv->sock);
    write(sk, "WELCOME\n", 8);
    for (size_t i = 0; i < srv->game_info.max_clients; ++i) {
        if (srv->players[i].sock == 0) {
            memset(&srv->players[i], 0, sizeof(player_t));
            srv->players[i].sock = sk;
            print_new_connection(srv->players[i].sock, &srv->srv);
            break;
        }
    }
}

static void read_write(server_t *srv)
{
    for (size_t i = 0; i < srv->game_info.max_clients; ++i) {
        srv->cur_cli_sock = srv->players[i].sock;
        if (FD_ISSET(srv->cur_cli_sock, &srv->fd)) {
            if (!listen_commands(srv, &srv->players[i])) {
                player_lst_pop(&srv->map->tiles[srv->players[i].pos->y]
                [srv->players[i].pos->x].players, &srv->players[i]);
                print_connection_closed(srv->players[i].sock);
                close(srv->cur_cli_sock);
                memset(&srv->players[i], 0, sizeof(player_t));
            }
        }
    }
}

static void init_srv(server_t *srv)
{
    int opt = 1;

    if ((srv->sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        print_error("socket error", srv->sock);
    if (setsockopt(srv->sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)))
        print_error("setsockopt error", srv->sock);
    srv->srv.sin_family = AF_INET;
    srv->srv.sin_port = htons(srv->port);
    srv->srv.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(srv->sock, (struct sockaddr *)&srv->srv, sizeof(srv->srv)) < 0)
        print_error("bind error", srv->sock);
    if (listen(srv->sock, 10) < 0)
        print_error("listen error", srv->sock);
    srv->size = sizeof(srv->srv);
    printf("Listening on port %ld...\n", srv->port);
}

static void launch_srv(server_t *srv)
{
    for (size_t i = 0; i < srv->game_info.max_clients; ++i)
        memset(&srv->players[i], 0, sizeof(player_t));
    while (1) {
        FD_ZERO(&srv->fd);
        FD_SET(srv->sock, &srv->fd);
        srv->max_cli_sock = srv->sock;
        for (size_t i = 0; i < srv->game_info.max_clients; ++i) {
            srv->cur_cli_sock = srv->players[i].sock;
            if (srv->cur_cli_sock > 0)
                FD_SET(srv->cur_cli_sock, &srv->fd);
            if (srv->cur_cli_sock > srv->max_cli_sock)
                srv->max_cli_sock = srv->cur_cli_sock;
        }
        if (select(srv->max_cli_sock + 1, &srv->fd, NULL, NULL, NULL) < 0)
            print_error("select error", srv->sock);
        if (FD_ISSET(srv->sock, &srv->fd))
            connection(srv);
        else
            read_write(srv);
    }
}

void start_server(server_t *srv)
{
    srv->map = malloc(sizeof(world_map_t));
    map_init(srv->map, srv->game_info.height, srv->game_info.width);
    init_srv(srv);
    launch_srv(srv);
    close(srv->sock);
}