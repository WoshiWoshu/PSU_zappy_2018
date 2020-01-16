/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** command_lst
*/

#include "command_lst.h"

#include <stdlib.h>
#include <stdio.h>

void command_lst_display(command_lst_t *head)
{
    command_lst_t *current = head;

    while (current != NULL) {
        printf("\"%s\" created at %ld\n", current->cmd->command,
        current->cmd->created_at);
        current = current->next;
    }
}

command_lst_t *command_lst_init(void)
{
    command_lst_t *new = malloc(sizeof(command_lst_t));

    new->cmd = NULL;
    new->next = NULL;
    return (new);
}

void command_lst_push(command_lst_t **head, command_t *cmd)
{
    command_lst_t *new = malloc(sizeof(command_lst_t));
    command_lst_t *current = *head;

    new->cmd = cmd;
    new->next = NULL;
    if (current == NULL) {
        *head = new;
        return;
    }
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new;
}

void command_lst_pop(command_lst_t **head)
{
    command_lst_t *current = *head;

    if (current != NULL)
        *head = current->next;
}