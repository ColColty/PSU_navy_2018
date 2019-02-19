/*
** EPITECH PROJECT, 2019
** map
** File description:
** map
*/

#ifndef MAP_H_
#define MAP_H_

#include <stdarg.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

typedef struct info_s {
    int start_x;
    int start_y;
    int finish;
    char nb_replace;
} info_t;

int recover_ship_position(char *filepath);

#endif
