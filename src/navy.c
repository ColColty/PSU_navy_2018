/*
** EPITECH PROJECT, 2019
** navy
** File description:
** navy
*/

#include "my.h"
#include "map.h"
#include "transmission.h"

int navy(int argc, char * const *argv)
{
    connection_t com;
    size_t n = 0;
    transmissions_t trans;
    unsigned int usecs = 200000;
    player_t player;
    char *buffer = NULL;

    if (argc == 2) {
        if (connect_player1(&com, &trans))
            return (1);
        recover_ship_position(argv[1], &player.player_one);
        game_loop(&trans, &com, 1);
    } else if (argc == 3) {
        com.attack_pid = my_atoi(argv[1]);
        if (connect_player2(&com, &trans))
            return (1);
        recover_ship_position(argv[2], &player.player_two);
        game_loop(&trans, &com, 2);
    }
    my_putstr(trans.attacant_input);
    my_putchar('\n');
    return (0);
}