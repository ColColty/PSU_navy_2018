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
    char *buffer = NULL;
    position_t position;

    if (argc == 2) {
        //player1(argv, &com);
        save_position(position, 1, argv[1]);
    }
    else if (argc == 3) {
        //player2(argv, &com);
        save_position(position, 2, argv[2]);
    }
    recover_ship_position(argv[1]);
    //while (1) {
    //    if (getline(buffer, 0, stdin) == -1)
    //        
    //}
    return (0);
}