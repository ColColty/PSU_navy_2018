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
    transmissions_t trans;
    unsigned int usecs = 200000;

    if (argc == 2) {
        if (connect_player1(&com, &trans))
            return (1);
        trans.user_input = "C3";
        usleep(usecs);
        send_signal(&com, &trans);
    } else if (argc == 3) {
        com.attack_pid = my_atoi(argv[1]);
        if (connect_player2(argv, &com, &trans))
            return (1);
        recieve_signal(&com, &trans);
    }
    return (0);
}