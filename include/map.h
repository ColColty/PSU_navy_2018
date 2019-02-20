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
    char **map;
} info_t;

int recover_ship_position(char *filepath);
char **create_the_map(info_t *info);
char **print_the_map(char **map, int player);
int gestion_first_player(info_t *player_one, char *buffer);
int gestion_second_player(info_t *player_two, char *buffer);

#endif
