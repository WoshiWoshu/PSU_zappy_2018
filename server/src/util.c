/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** util
*/

#include "util.h"

#include <unistd.h>

bool check_team(char **teams, const char *team)
{
    for (unsigned int i = 0; teams[i] != NULL; ++i) {
        if (!strcmp(teams[i], team))
            return (true);
    }
    return (false);
}

bool is_in_array(const char **arr, const char *val, int *index)
{
    *index = -1;

    for (unsigned int i = 0; arr[i] != NULL; ++i) {
        if (!strcmp(arr[i], val)) {
            *index = i;
            return (true);
        }
    }
    return (false);
}

void write_msg(int sk, const char *msg)
{
    write(sk, msg, strlen(msg));
}
