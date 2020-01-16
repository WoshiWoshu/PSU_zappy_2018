/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** player
*/

#include "player.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "collectibles.h"

void player_init(player_t *player, char *team_name, coordinate_t *pos)
{
    player->food = 10;
    player->level = 1;
    player->team = malloc(strlen(team_name) + 1);
    strcpy(player->team, team_name);
    player->pos = pos;
    for (size_t i = 0; i < 6; i++)
        player->stones[i] = 0;
    player->dir = rand() % 4;
}

void player_delete(player_t *player)
{
    player->food = 0;
    player->level = 0;
    free(player->team);
    player->team = NULL;
    player->pos = NULL;
}

bool player_equal(const player_t *p1, const player_t *p2)
{
    return (p1->sock == p2->sock
            && p1->read_size == p2->read_size
            && strcmp(p1->team, p2->team) == 0
            && p1->level == p2->level
            && p1->food == p2->food
            && p1->stones[0] == p2->stones[0]
            && p1->stones[1] == p2->stones[1]
            && p1->stones[2] == p2->stones[2]
            && p1->stones[3] == p2->stones[3]
            && p1->stones[4] == p2->stones[4]
            && p1->stones[5] == p2->stones[5]
            && p1->dir == p2->dir);
}

void player_display(const player_t *player)
{
    char *look_to = malloc(6);

    if (player->dir == 0)
        strcpy(look_to, "up");
    if (player->dir == 1)
        strcpy(look_to, "down");
    if (player->dir == 2)
        strcpy(look_to, "right");
    if (player->dir == 3)
        strcpy(look_to, "left");
    printf("player sock: %d, team: %s, level: %ld, dir: %s\n\t [food: %ld,"
    " linemate %ld, deraumere %ld, sibur %ld, mendiane %ld,"
    " phiras %ld, thystame %ld]\n", player->sock, player->team, player->level,
    look_to, player->food, player->stones[LINEMATE],
    player->stones[DERAUMERE], player->stones[SIBUR], player->stones[MENDIANE],
    player->stones[PHIRAS], player->stones[THYSTAME]);
    free(look_to);
}