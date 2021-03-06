/*
** EPITECH PROJECT, 2019
** map.c
** File description:
** Draw the map
*/

#include "my.h"
#include "map.h"

int recover_ship_position(char *filepath, player_t *player)
{
    char *buffer = NULL;
    int fd = open(filepath, O_RDONLY);
    int size = 0;

    if (fd == -1)
        return (-1);
    if ((buffer = malloc(sizeof(char) * 32)) == NULL)
        return (-1);
    if ((size = read(fd, buffer, 32)) == 0)
        return (-1);
    close(fd);
    gestion_first_player(&player->player_defender, buffer);
    player->player_enemy.map = create_the_map();
    if (player->player_defender.map == NULL
        || player->player_enemy.map == NULL)
        return (-1);
    print_hud(player);
    free(buffer);
    return (0);
}
