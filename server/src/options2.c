/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** options2
*/

#include "options2.h"

#include <stdlib.h>
#include <stdbool.h>

static bool has_duplicates(char **teams)
{
    for (size_t i = 0; teams[i] != NULL; ++i) {
        for (size_t j = 0; teams[j] != NULL; ++j) {
            if (i != j && !strcmp(teams[i], teams[j]))
                return (true);
        }
    }
    return (false);
}

static void option_n2(game_info_t *g, const char **args, size_t index)
{
    int tmp_index = index + 1;
    int nb_teams = 0;
    int i = 0;

    while (args[tmp_index] != NULL && args[tmp_index][0] != '-') {
        ++nb_teams;
        ++tmp_index;
    }
    g->teams = malloc(sizeof(char *) * (nb_teams + 1));
    memset(g->teams, 0, sizeof(char *) * (nb_teams + 1));
    tmp_index = index + 1;
    while (args[tmp_index] != NULL && args[tmp_index][0] != '-') {
        g->teams[i] = malloc(strlen(args[tmp_index]) + 1);
        strcpy(g->teams[i], args[tmp_index]);
        ++i;
        ++tmp_index;
    }
    g->max_clients = i * g->nb_clients;
}

int option_n(game_info_t *g, player_t **p, const char **args, size_t index)
{
    int error = 0;

    if (args[index + 1] == NULL) {
        error = -1;
        printf("option requires an argument -- 'n'\n\n");
    } else {
        option_n2(g, args, index);
        if (has_duplicates(g->teams)) {
            error = -1;
            printf("-n option only accepts unique team names\n\n");
        } else
            *p = malloc(sizeof(player_t) * g->max_clients);
    }
    return (error);
}

void init_default_teams(game_info_t *g, player_t **p)
{
    g->teams = malloc(sizeof(char *) * 3);
    g->teams[0] = malloc(6);
    strcpy(g->teams[0], "team1");
    g->teams[1] = malloc(6);
    strcpy(g->teams[1], "team2");
    g->max_clients = 2 * g->nb_clients;
    *p = malloc(sizeof(player_t) * g->max_clients);
}
