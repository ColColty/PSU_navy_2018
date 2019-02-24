/*
** EPITECH PROJECT, 2019
** Map tool
** File description:
** Tool for create the map
*/

#include "my.h"
#include "map.h"

static void print_the_map(char **map)
{
    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    for (int i = 0; i != 8; i++) {
        my_put_nbr(i + 1);
        my_putchar('|');
        my_putstr(map[i]);
        my_putchar('\n');
    }
}

void print_hud(player_t *player)
{
    my_putstr("\nmy positions: \n");
    print_the_map(player->player_defender.map);
    my_putstr("\nenemy's positions:\n");
    print_the_map(player->player_enemy.map);
}

char *create_the_map(void)
{
    char **map = malloc(sizeof(char *) * 8);
    int k = 0;

    for (int i = 0; i != 8; i++) {
        map[i] = malloc(sizeof(char) * 16);
        for (k = 0; k < 16; k += 2) {
            map[i][k] = '.';
            map[i][k + 1] = ' ';
        }
    }
    return (map);
}