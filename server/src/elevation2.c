/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** elevation2
*/

#include "elevation2.h"

static bool check_players2(player_t *player, size_t count)
{
    if (player->level == 6 && count >= 6)
        return (true);
    if (player->level == 7 && count >= 6)
        return (true);
    return (false);
}

bool check_players(player_lst_t *lst, player_t *player)
{
    size_t count = 0;
    player_lst_t *current = lst;

    while (current != NULL) {
        if (current->player->level == player->level)
            count++;
        current = current->next;
    }
    if (player->level == 1 && count >= 1)
        return (true);
    if (player->level == 2 && count >= 2)
        return (true);
    if (player->level == 3 && count >= 2)
        return (true);
    if (player->level == 4 && count >= 4)
        return (true);
    if (player->level == 5 && count >= 4)
        return (true);
    return (check_players2(player, count));
}