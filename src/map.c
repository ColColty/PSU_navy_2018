/*
** EPITECH PROJECT, 2019
** map.c
** File description:
** Draw the map
*/

#include "include/my.h"
#include "include/map.h"

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

char **get_position(char *position, info_t *info)
{
    int i = 0;
    
    while (position[i] != '\0') {
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

char **print_the_map(char **map)
{
    int k = 1;

    my_putstr("my positions: \n");
    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    for (int i = 0; i != 8; i++) {
        my_put_nbr(k);
        my_putchar('|');
        my_putstr(map[i]);
        my_putchar('\n');
        k++;
    }
}

char **create_the_map(info_t *info)
{
    info->map = malloc(sizeof(char *) * 128);
    int i = 0;
    int k = 0;

    for (i = 0; i != 8; i++) {
        info->map[i] = malloc(sizeof(char) * 16);
        for (k = 0; k != 16; k += 2) {
            info->map[i][k] = '.';
            info->map[i][k + 1] = ' ';
        }
    }
}

int recover_ship_position(char *filepath)
{
    info_t info;
    char *buffer = NULL;
    int fd = open(filepath, O_RDONLY);

    if (fd == -1)
        return (84);
    buffer = malloc(sizeof(char) * 32);
    read(fd, buffer, 32);
    buffer[33] = '\0';
    close(fd);
    create_the_map(&info);
    get_position(buffer, &info);
    print_the_map(info.map);
    return (0);
}