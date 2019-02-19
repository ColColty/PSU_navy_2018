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
        if (i == '\0')
            return (i);
        else
            i++;
    }
    i += 1;
    return (i);
}

char **add_position2(char **map, info_t *info)
{
    
    int i = info->start_y - 1;
    int k = info->start_x * 2;
    my_put_nbr(info->finish);
    my_putchar('\n');

    while (k != info->finish) {
        map[i][k] = info->nb_replace;
        k++;
    }
}

char **add_position(char **map, info_t *info)
{
    int i = info->start_y - 1;
    int k = info->start_x * 2;

    while (i != info->finish) {
        map[i][k] = info->nb_replace;
        i++;
    }
}

char **get_position(char **map, char *position, info_t *info)
{
    int i = 0;
    
    while (position[i] != '\0') {
        info->nb_replace = position[i];
        i += 2;
        if (position[i] == position[i + 3]) {
            info->start_x = position[i] - 65;
            info->start_y = position[i + 1] - 48;
            info->finish = position[i + 4] - 48;
            add_position(map, info);
            i = change_line(position, i);
        }
        else {
            info->start_x = position[i] - 65;
            info->start_y = position[i + 1] - 48;
            info->finish = position[i + 3] - position[i];
            add_position2(map, info);
            i = change_line(position, i);
        }
    }
    return (map);
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

char **create_the_map(void)
{
    char **map = malloc(sizeof(char *) * 128);
    int i = 0;
    int k = 0;

    for (i = 0; i != 8; i++) {
        map[i] = malloc(sizeof(char) * 16);
        for (k = 0; k != 16; k += 2) {
            map[i][k] = '.';
            map[i][k + 1] = ' ';
        }
    }
    return (map);
}

int recover_ship_position(char *filepath)
{
    info_t info;
    char *buffer = NULL;
    int fd = open(filepath, O_RDONLY);
    char **map;

    if (fd == -1)
        return (84);
    buffer = malloc(sizeof(char) * 32);
    read(fd, buffer, 32);
    buffer[33] = '\0';
    close(fd);
    map = create_the_map();
    print_the_map(map);
    //map = get_position(map, buffer, &info);
    //print_the_map(map);
    return (0);
}