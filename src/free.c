/*
** EPITECH PROJECT, 2019
** free
** File description:
** free
*/

#include "map.h"

int free_everything(player_t *player)
{
    for (int i = 0; i < 8; i++) {
        free(player->player_defender.map[i]);
        free(player->player_enemy.map[i]);
    }
    free(player->player_defender.map);
    free(player->player_enemy.map);
    return (0);
}
