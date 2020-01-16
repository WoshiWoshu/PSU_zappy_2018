/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** server_cmds
*/

#include "server_cmds.h"

#include "server_util.h"
#include "server_cmds1.h"
#include "server_cmds2.h"
#include "movement.h"
#include "broadcast.h"

static void player_join_team(server_t *srv, player_t *player, char *buf)
{
    int nb = 0;
    char response[255] = {0};
    coordinate_t *spawn = malloc(sizeof(coordinate_t));

    if (check_team(srv->game_info.teams, buf)) {
        spawn->x = rand() % srv->game_info.width;
        spawn->y = rand() % srv->game_info.height;
        player_init(player, buf, spawn);
        player_lst_push(&srv->map->tiles[spawn->y][spawn->x].players, player);
        if ((nb = connect_nbr(srv, buf)) < 0) {
            player_delete(player);
            write(player->sock, "ko\n", 3);
        } else {
            sprintf(response, "%d\n", nb);
            write(player->sock, response, strlen(response));
            sprintf(response, "%ld %ld\n", srv->game_info.width,
            srv->game_info.height);
            write(player->sock, response, strlen(response));
        }
    } else
        write(player->sock, "ko\n", 3);
}

static void listen_commands4(server_t *srv, player_t *player, char *buf)
{
    if (!strncmp("Eject", buf, 5)) {
        write_eject(srv->map, player);
        return;
    }
    if (!strncmp("Broadcast", buf, 9)) {
        start_broadcast(srv, player, buf + 10);
        write_msg(player->sock, "ok\n");
        return;
    } else {
        write_msg(player->sock, "ko\n");
        return;
    }
}

static void listen_commands3(server_t *srv, player_t *player, char *buf)
{
    if (!strncmp("Take", buf, 4)) {
        write_take(srv->map, player, buf + 5);
        return;
    }
    if (!strncmp("Set", buf, 3)) {
        write_drop(srv->map, player, buf + 4);
        return;
    }
    if (!strncmp("Incantation", buf, 11)) {
        write_incantation(srv->map, player);
        return;
    }
    if (!strncmp("Fork", buf, 4)) {
        write_msg(player->sock, "ok\n");
        return;
    }
    listen_commands4(srv, player, buf);
}

static void listen_commands2(server_t *srv, player_t *player, char *buf)
{
    if (!strncmp("Look", buf, 4)) {
        write_look(srv->map, player);
        return;
    }
    if (!strncmp("Forward", buf, 7)) {
        move_forward(srv->map, player);
        write_msg(player->sock, "ok\n");
        return;
    }
    if (!strncmp("Right", buf, 5)) {
        turn_right(player);
        write_msg(player->sock, "ok\n");
        return;
    }
    if (!strncmp("Left", buf, 4)) {
        turn_left(player);
        write_msg(player->sock, "ok\n");
        return;
    }
    listen_commands3(srv, player, buf);
}

bool listen_commands(server_t *srv, player_t *player)
{
    char buf[255] = {0};

    if ((player->read_size = read(player->sock, buf, 255)) == 0)
        return (false);
    buf[strlen(buf) - 1] = 0;
    if (!player->team)
        player_join_team(srv, player, buf);
    else {
        if (!strncmp("Connect_nbr", buf, 11))
            write_int(player->sock, connect_nbr(srv, player->team));
        else if (!strncmp("Inventory", buf, 9))
            write_inventory(player);
        else
            listen_commands2(srv, player, buf);
    }
    return (true);
}