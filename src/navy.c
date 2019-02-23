/*
** EPITECH PROJECT, 2019
** navy
** File description:
** navy
*/

#include "my.h"
#include "map.h"
#include "transmission.h"

int verif_win(void)
{
    printf("BONJOUR");
}

int navy(int argc, char * const *argv)
{
    connection_t com;
    char *buffer = NULL;
    position_t position;
    size_t n = 0;
    transmissions_t trans;

    if (argc == 2) {
        if (connect_player1(&com, &trans))
            return (1);
        recover_ship_position(argv[1]);
        game_loop(&trans, &com, 1);
    } else if (argc == 3) {
        com.attack_pid = my_atoi(argv[1]);
        if (connect_player2(&com, &trans))
            return (1);
        recover_ship_position(argv[2]);
        game_loop(&trans, &com, 2);
    }
    my_putstr(trans.attacant_input);
    my_putchar('\n');
    return (0);
}