/*
** EPITECH PROJECT, 2019
** gestion player two
** File description:
** function for the gestion of the second player
*/

#include "my.h"
#include "map.h"

int **create_map(char **map)
{
    map = malloc(sizeof(char *) * 128);

    for (int i = 0; i != 8; i ++) {
        map[i] = malloc(sizeof(char) * 16);
        for (int k = 0; k != 16; k += 2) {
            map[i][k] = '.';
            map[i][k + 1] = ' ';
        }
    }
    return (map);
}

char **create_map_defender(char **map)
{
    map = create_map(map);
    my_putchar('\n');
    print_the_map(map, 2);
    return (map);
}
