/*
** EPITECH PROJECT, 2019
** map.c
** File description:
** Draw the map
*/

#include "my.h"
#include "map.h"

int recover_ship_position(char *filepath, info_t *player)
{
    char *buffer = NULL;
    int fd = open(filepath, O_RDONLY);
    char **map = NULL;

    if (fd == -1)
        return (84);
    buffer = malloc(sizeof(char) * 32);
    read(fd, buffer, 32);
    buffer[33] = '\0';
    close(fd);
    gestion_first_player(&player, buffer);
    create_map_defender(map);
    free(buffer);
    return (0);
}