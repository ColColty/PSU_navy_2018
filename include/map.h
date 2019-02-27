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
#include <stdio.h>

#define TRANS(value) ((value > 57) ? (value - 65) : (value - 48))

typedef struct {
    int start_x;
    int start_y;
    int finish;
    char nb_replace;
    char **map;
} info_t;

typedef struct {
    info_t player_defender;
    info_t player_enemy;
} player_t;

int recover_ship_position(char *filepath, player_t *player);
char **create_the_map(void);
void print_hud(player_t *player);
int gestion_first_player(info_t *player_defender, char *buffer);
void create_map_defender(info_t *player);
int main_error_gestion(char *pathfile);

#endif
