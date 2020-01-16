/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** main
*/

#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "server.h"
#include "help.h"
#include "options.h"

int main(int argc, char const *argv[])
{
    server_t srv;

    srand(time(NULL));
    if (argc == 2 && !strcmp(argv[1], "-help"))
        help();
    else {
        if (!check_params_and_init(argv, &srv)) {
            help();
            return (84);
        } else
            start_server(&srv);
    }
    return (0);
}
