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
    size_t n = 0;
    transmissions_t trans;
    unsigned int usecs = 200000;
    player_t player;
    char *buffer = NULL;

    if (argc == 2) {
        if (connect_player1(&com, &trans))
            return (1);
        trans.user_input = "F1";
        usleep(usecs);
        send_signal(&com, &trans);
        recover_ship_position(argv[1], &player.player_one);
    } else if (argc == 3) {
        com.attack_pid = my_atoi(argv[1]);
        if (connect_player2(&com, &trans))
            return (1);
        recieve_signal();
        recover_ship_position(argv[2], &player.player_two);
    }
    while(1) {
        read(0, buffer, 2);
        my_strcpy(trans.user_input, buffer);    
        send_signal(&com, &trans);
    }
    my_putstr(trans.attacant_input);
    my_putchar('\n');
    return (0);
}