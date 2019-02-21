/*
** EPITECH PROJECT, 2019
** navy
** File description:
** navy
*/

#include "my.h"
#include "map.h"

int verif_win(void)
{
    
}

int navy(int argc, char * const *argv)
{
    connection_t com;
    char *buffer = NULL;
    size_t n = 0;
    info_t player_one;
    info_t player_two;

    if (argc == 2) {
        player1(argv, &com);
        recover_ship_position(argv[1], player_one);
    }
    else if (argc == 3) {
        player2(argv, &com);
        recover_ship_position(argv[2], player_two);
    }
    while (1) {
        if (getline(&buffer, &n, stdin) == -1)
            exit (0);
        
        }
    return (0);
}