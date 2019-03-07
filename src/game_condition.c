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
    && player->map[TRANS(coor[1]) - 1][TRANS(coor[0]) * 2] <= '9'
    || player->map[TRANS(coor[1]) - 1][TRANS(coor[0]) * 2] == 'x') {
        my_putstr(": hit\n");
        if (kill(com->attack_pid, SIGUSR2) == -1)
            return (-1);
        player->map[TRANS(coor[1]) - 1][TRANS(coor[0]) * 2] = 'x';
        return (0);
    }
    my_putstr(": missed\n");
    if (kill(com->attack_pid, SIGUSR1) == -1)
        return (-1);
    player->map[TRANS(coor[1]) - 1][TRANS(coor[0]) * 2] = 'o';
    return (1);
}

int find_all_boats(info_t *player)
{
    int counter = 0;

    for (int i = 0; player->map[i] != NULL; i++)
        for (int k = 0; player->map[i][k] != '\0'; k++)
            if (player->map[i][k] == 'x')
                counter++;
    if (counter != 14)
        return (0);
    return (1);
}

int game_condition(player_t *player, connection_t *com)
{
    if (find_all_boats(&player->player_defender)) {
        my_putstr("\nEnemy won\n");
        return (89);
    }
    if (find_all_boats(&player->player_enemy)) {
        my_putstr("\nI won\n");
        return (99);
    }
    return (0);
}
