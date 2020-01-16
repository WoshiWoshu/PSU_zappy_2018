/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** command_lst
*/

#ifndef COMMAND_LST_H_
#define COMMAND_LST_H_

#include "command.h"

typedef struct command_lst_s {
    command_t *cmd;
    struct command_lst_s *next;
} command_lst_t;

void command_lst_display(command_lst_t *);
command_lst_t *command_lst_init(void);
void command_lst_push(command_lst_t **, command_t *);
void command_lst_pop(command_lst_t **);


#endif /* !COMMAND_LST_H_ */
