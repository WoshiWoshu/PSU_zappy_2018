/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** look2
*/

#include "look2.h"

#include <string.h>

static void add_tile_to_msg2(const tiles_t *tile, char *msg)
{
    for (size_t i = 0; i < tile->stones[PHIRAS]; i++)
        strcat(msg, " phiras");
    for (size_t i = 0; i < tile->stones[THYSTAME]; i++)
        strcat(msg, " thystame");
    strcat(msg, ",");
}

void add_tile_to_msg(const tiles_t *tile, char *msg)
{
    player_lst_t *current = tile->players;

    while (current != NULL) {
        strcat(msg, " player");
        current = current->next;
    }
    for (size_t i = 0; i < tile->food; i++)
        strcat(msg, " food");
    for (size_t i = 0; i < tile->stones[LINEMATE]; i++)
        strcat(msg, " linemate");
    for (size_t i = 0; i < tile->stones[DERAUMERE]; i++)
        strcat(msg, " deraumere");
    for (size_t i = 0; i < tile->stones[SIBUR]; i++)
        strcat(msg, " sibur");
    for (size_t i = 0; i < tile->stones[MENDIANE]; i++)
        strcat(msg, " mendiane");
    add_tile_to_msg2(tile, msg);
}