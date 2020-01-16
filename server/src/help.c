/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** help
*/

#include "help.h"

#include <stdio.h>

void help(void)
{
    printf("USAGE: ./zappy_server -p port -x width -y height -n name1 name2");
    printf(" ... -c clientsNb -f freq\n");
    printf("\tport\t\tis the port number\n");
    printf("\twidth\t\tis the width of the world\n");
    printf("\theight\t\tis the height of the world\n");
    printf("\tnameX\t\tis the name of the team X\n");
    printf("\tclientsNb\tis the number of authorized clients per team\n");
    printf("\tfreq\t\t");
    printf("is the reciprocal of time unit for execution of actions\n");
}

char *clean_look(char *msg)
{
    bool comma = false;

    for (size_t i = 0; msg[i] != '\0'; i++) {
        if (comma && msg[i] == ' ') {
            memmove(&msg[i], &msg[i + 1], strlen(msg) - i);
            comma = false;
        } else if (msg[i] == ',')
            comma = true;
        else
            comma = false;
    }
    return (msg);
}