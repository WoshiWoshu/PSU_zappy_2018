/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** player_lst
*/

#ifndef PLAYER_LST_H_
#define PLAYER_LST_H_

#include "player.h"

typedef struct player_lst_s {
    player_t *player;
    struct player_lst_s *next;
} player_lst_t;

void player_lst_display(player_lst_t *);
player_lst_t *player_lst_init(void);
void player_lst_push(player_lst_t **, player_t *);
void player_lst_pop(player_lst_t **, const player_t *);

#endif /* !PLAYER_LST_H_ */
