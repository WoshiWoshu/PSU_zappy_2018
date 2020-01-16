/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** player_lst
*/

#include "player_lst.h"

#include <stdlib.h>

void player_lst_display(player_lst_t *head)
{
    player_lst_t *current = head;

    while (current != NULL) {
        player_display(current->player);
        current = current->next;
    }
}

player_lst_t *player_lst_init(void)
{
    player_lst_t *new = malloc(sizeof(player_lst_t));

    new->player = NULL;
    new->next = NULL;
    return (new);
}

void player_lst_push(player_lst_t **head, player_t *player)
{
    player_lst_t *new = malloc(sizeof(player_lst_t));
    player_lst_t *current = *head;

    new->player = player;
    new->next = NULL;
    if (current == NULL) {
        *head = new;
        return;
    }
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new;
}

void player_lst_pop(player_lst_t **head, const player_t *player)
{
    player_lst_t *current = *head;
    player_lst_t *current_n1 = *head;

    if (current != NULL && player_equal(player, current->player)) {
        *head = current->next;
        return;
    }
    while (current != NULL) {
        if (player_equal(player, current->player)) {
            current_n1->next = current->next;
            break;
        }
        current_n1 = current;
        current = current->next;
    }
}