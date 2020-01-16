/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** server_util
*/

#include "server_util.h"

#include <string.h>

#include "interaction.h"

void print_new_connection(int sk, struct sockaddr_in *srv)
{
    printf("New connection detected. Socket fd is %d. ", sk);
    printf("IP is: %s", inet_ntoa(srv->sin_addr));
    printf(":%d\n", ntohs(srv->sin_port));
}

void print_connection_closed(int sk)
{
    printf("Client with socket fd %d disconnected.\n", sk);
}

void print_error(const char *message, int srv_socket)
{
    perror(message);
    close(srv_socket);
    exit(84);
}

void write_int(int sk, int val)
{
    char response[255] = {0};

    sprintf(response, "%d\n", val);
    write(sk, response, strlen(response));
}

void write_inventory(player_t *p)
{
    char *inventory = malloc(255);

    memset(inventory, 0, 255);
    inventory = get_inventory(p, inventory);
    write(p->sock, inventory, strlen(inventory));
    free(inventory);
}
