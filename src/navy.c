/*
** EPITECH PROJECT, 2019
** navy
** File description:
** navy
*/

#include "my.h"
#include "map.h"

int navy(int argc, char * const *argv)
{
    connection_t com;

    if (argc == 2)
        player1(argv, &com);
    else if (argc == 3)
        player2(argv, &com);
    recover_ship_position(argv[1]);
    return (0);
}