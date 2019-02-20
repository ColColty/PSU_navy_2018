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
    game_t game;
    unsigned int usecs = 2000000;

    if (argc == 2) {
        if (connect_player1(&com))
            return (1);
        game.user_input = "B";
        usleep(usecs);
        send_signal(&com, &game);
    } else if (argc == 3) {
        if (connect_player2(argv, &com))
            return (1);
        recieve_signal(&com, &game);
    }
    recover_ship_position(argv[1]);
    return (0);
}