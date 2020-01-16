/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** options1
*/

#include "options1.h"

#include <stdlib.h>

int option_p(size_t *port, const char **args, size_t index)
{
    size_t tmp_port = 0;
    int error = 0;

    if (args[index + 1] == NULL) {
        error = -1;
        printf("option requires an argument -- 'p'\n\n");
    } else {
        tmp_port = atoi(args[index + 1]);
        if (tmp_port == 0) {
            error = -1;
            printf("-p option only accepts valid ports\n\n");
        } else
            *port = tmp_port;
    }
    return (error);
}

int option_x(size_t *width, const char **args, size_t index)
{
    size_t tmp_width = 0;
    int error = 0;

    if (args[index + 1] == NULL) {
        error = -1;
        printf("option requires an argument -- 'x'\n\n");
    } else {
        tmp_width = atoi(args[index + 1]);
        if (tmp_width < 10 || tmp_width > 30) {
            error = -1;
            printf("-x option only accepts integer values between 10 and 30");
            printf("\n\n");
        } else
            *width = tmp_width;
    }
    return (error);
}

int option_y(size_t *height, const char **args, size_t index)
{
    size_t tmp_height = 0;
    int error = 0;

    if (args[index + 1] == NULL) {
        error = -1;
        printf("option requires an argument -- 'y'\n\n");
    } else {
        tmp_height = atoi(args[index + 1]);
        if (tmp_height < 10 || tmp_height > 30) {
            error = -1;
            printf("-y option only accepts integer values between 10 and 30");
            printf("\n\n");
        } else
            *height = tmp_height;
    }
    return (error);
}

int option_c(size_t *clients_nb, const char **args, size_t index)
{
    size_t tmp_clients_nb = 0;
    int error = 0;

    if (args[index + 1] == NULL) {
        error = -1;
        printf("option requires an argument -- 'c'\n\n");
    } else {
        tmp_clients_nb = atoi(args[index + 1]);
        if (tmp_clients_nb == 0) {
            error = -1;
            printf("-c option only accepts integer values greater or ");
            printf("equal to 1\n\n");
        } else
            *clients_nb = tmp_clients_nb;
    }
    return (error);
}

int option_f(size_t *freq, const char **args, size_t index)
{
    size_t tmp_freq = 0;
    int error = 0;

    if (args[index + 1] == NULL) {
        error = -1;
        printf("option requires an argument -- 'f'\n\n");
    } else {
        tmp_freq = atoi(args[index + 1]);
        if (tmp_freq < 2 || tmp_freq > 10000) {
            error = -1;
            printf("-f option only accepts integer values between 2 and 10000");
            printf("\n\n");
        } else
            *freq = tmp_freq;
    }
    return (error);
}
