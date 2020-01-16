/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** player
*/

#ifndef PLAYER_H_
#define PLAYER_H_

#include <unistd.h>
#include <stdbool.h>

enum direction {
    UP = 0,
    DOWN = 1,
    RIGHT = 2,
    LEFT = 3
};

typedef struct coordinate_s {
    size_t x;
    size_t y;
} coordinate_t;

typedef struct player_s {
    int sock;
    ssize_t read_size;
    char *team;
    size_t level;
    coordinate_t *pos;
    size_t food;
    size_t stones[6];
    enum direction dir;
} player_t;

void player_init(player_t *, char *, coordinate_t *);
void player_delete(player_t *);
bool player_equal(const player_t *, const player_t *);
void player_display(const player_t *);

#endif /* !PLAYER_H_ */
