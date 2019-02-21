/*
** EPITECH PROJECT, 2019
** gestion player two
** File description:
** function for the gestion of the second player
*/

#include "my.h"
#include "map.h"

int gestion_second_player(info_t *player_two, char *buffer)
{
    create_the_map(player_two);
    my_putchar('\n');
    print_the_map(player_two->map, 2);
}
