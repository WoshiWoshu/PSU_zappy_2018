/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** options
*/

#include "options.h"

#include "util.h"

static bool check_params_and_init2(const char **av, server_t *s)
{
    int index = 0;

    if (is_in_array(av, "-c", &index)) {
        if (option_c(&s->game_info.nb_clients, av, index) == -1)
            return (false);
    } else
        s->game_info.nb_clients = 3;
    if (is_in_array(av, "-f", &index)) {
        if (option_f(&s->game_info.freq, av, index) == -1)
            return (false);
    } else
        s->game_info.freq = 2;
    if (is_in_array(av, "-n", &index)) {
        if (option_n(&s->game_info, &s->players, av, index) == -1)
            return (false);
    } else
        init_default_teams(&s->game_info, &s->players);
    return (true);
}

bool check_params_and_init(const char **av, server_t *s)
{
    int index = 0;

    if (is_in_array(av, "-p", &index)) {
        if (option_p(&s->port, av, index) == -1)
            return (false);
    } else
        s->port = 4242;
    if (is_in_array(av, "-x", &index)) {
        if (option_x(&s->game_info.width, av, index) == -1)
            return (false);
    } else
        s->game_info.width = 10;
    if (is_in_array(av, "-y", &index)) {
        if (option_y(&s->game_info.height, av, index) == -1)
            return (false);
    } else
        s->game_info.height = 10;
    return (check_params_and_init2(av, s));
}
