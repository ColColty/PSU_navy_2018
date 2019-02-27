/*
** EPITECH PROJECT, 2019
** Game condition
** File description:
** WIning or losing condition
*/

#include "map.h"
#include "my.h"
#include "transmission.h"

int touch_or_not(char *coor, info_t *player, connection_t *com)
{
    if (player->map[TRANS(coor[1]) - 1][TRANS(coor[0]) * 2] >= '1'
    && player->map[TRANS(coor[1]) - 1][TRANS(coor[0]) * 2] <= '9') {
        my_putstr(": hit\n");
        kill(com->attack_pid, SIGUSR2);
        return (0);
    }
    my_putstr(": missed\n");
    kill(com->attack_pid, SIGUSR1);
    return (1);
}

int game_condition(info_t *player)
{
    for (int i = 0; player->map[i] != NULL; i++) {
        for (int k = 0; player->map[i][k] != '\0'; k++) {
            if (player->map[i][k] >= '1' && player->map[i][k] <= '9')
                return (1);
        }
    }
    my_putstr("I won");
    // Send a signal to the enemy
    return (0);
}