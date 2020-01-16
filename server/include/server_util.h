/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** server_util
*/

#ifndef SERVER_UTIL_H_
#define SERVER_UTIL_H_

#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "player.h"

void print_new_connection(int, struct sockaddr_in *);
void print_connection_closed(int);
void print_error(const char *, int);
void write_int(int, int);
void write_inventory(player_t *);

#endif /* !SERVER_UTIL_H_ */
