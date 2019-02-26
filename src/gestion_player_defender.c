/*
** EPITECH PROJECT, 2019
** gestion for the first player
** File description:
** player one gestion
*/

#include "my.h"
#include "map.h"

int change_line(char *position, int i)
{
    while (position[i] != '\n') {
        if (position[i] == '\0')
            return (i);
        i++;
    }
    i += 1;
    return (i);
}

char **add_position2(char **map, info_t *info)
{
    int i = info->start_y - 1;
    int k = info->start_x * 2;

    while (k <= info->finish * 2) {
        map[i][k] = info->nb_replace;
        k += 2;
    }
    return (map);
}

char **add_position(char **map, info_t *info)
{
    int i = info->start_y - 1;
    int k = info->start_x * 2;

    while (i != info->finish) {
        map[i][k] = info->nb_replace;
        i++;
    }
    return (map);
}

void get_position(char *position, info_t *info)
{
    int i = 0;

    while (i < 32) {
        info->nb_replace = position[i];
        i += 2;
        if (position[i] == position[i + 3]) {
            info->start_x = position[i] - 65;
            info->start_y = position[i + 1] - 48;
            info->finish = position[i + 4] - 48;
            add_position(info->map, info);
            i = change_line(position, i);
        }
        else {
            info->start_x = position[i] - 65;
            info->start_y = position[i + 1] - 48;
            info->finish = position[i + 3] - 65;
            add_position2(info->map, info);
            i = change_line(position, i);
        }
    }
}

int gestion_first_player(info_t *player, char *buffer)
{
    player->map = create_the_map();
    get_position(buffer, player);
    return (0);
}