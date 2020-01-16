/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** interaction
*/

#ifndef INTERACTION_H_
#define INTERACTION_H_

#include "player.h"
#include "collectibles.h"
#include "map.h"

char *take_stone(world_map_t *, player_t *, stones_t, char *);
char *drop_stone(world_map_t *, player_t *, stones_t, char *);
char *take_food(world_map_t *, player_t *, char *);
char *drop_food(world_map_t *, player_t *, char *);
char *get_inventory(const player_t *, char *);

#endif /* !INTERACTION_H_ */
