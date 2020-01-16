/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** command
*/

#ifndef COMMAND_H_
#define COMMAND_H_

#include <time.h>

typedef struct command_s {
    char *command;
    time_t created_at;
} command_t;

#endif /* !COMMAND_H_ */
