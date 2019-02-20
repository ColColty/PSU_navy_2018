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
        trans.user_input = "F1";
        usleep(usecs);
        send_signal(&com, &trans);
    } else if (argc == 3) {
        if (connect_player2(argv, &com, &trans))
            return (1);
        recieve_signal();
    }
    my_putstr(trans.attacant_input);
    my_putchar('\n');
    recover_ship_position(argv[1]);
    return (0);
}