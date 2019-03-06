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
    transmissions_t trans;
    player_t player;

    if (argc == 2) {
        if (connect_player1(&com, &trans))
            return (1);
        recover_ship_position(argv[1], &player);
        if (game_loop_p1(&com, &trans, &player) == -1)
            return (1);
    } else if (argc == 3) {
        com.attack_pid = my_atoi(argv[1]);
        if (connect_player2(&com, &trans))
            return (1);
        recover_ship_position(argv[2], &player);
        if (game_loop_p2(&com, &trans, &player) == -1)
            return (1);
    }
   free_everything(&player);
   return (0);
}