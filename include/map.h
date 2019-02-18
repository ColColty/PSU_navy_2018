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

typedef struct map {
    char **map_player_one;
    char **map_player_two;
} map_t;


int print_map(char *pathfile);

#endif
