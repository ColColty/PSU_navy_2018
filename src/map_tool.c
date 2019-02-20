/*
** EPITECH PROJECT, 2019
** Map tool
** File description:
** Tool for create the map
*/

#include "include/my.h"
#include "include/map.h"

char **print_the_map(char **map, int player)
{
    int k = 1;

    if (player == 1)
        my_putstr("my positions: \n");
    else
        my_putstr("enemy's positions:\n");
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