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
    printf("BONJOUR");
}
int navy(int argc, char * const *argv)
{
    connection_t com;
    char *buffer = NULL;
    position_t position;
    size_t n = 0;
    transmissions_t trans;
    unsigned int usecs = 200000;

    if (argc == 2) {
        if (connect_player1(&com, &trans))
            return (1);
        trans.user_input = "F1";
        usleep(usecs);
        send_signal(&com, &trans);
        recover_ship_position(argv[1]);
    } else if (argc == 3) {
        com.attack_pid = my_atoi(argv[1]);
        if (connect_player2(&com, &trans))
            return (1);
        recieve_signal();
        recover_ship_position(argv[2]);
    }
    my_putstr(trans.attacant_input);
    my_putchar('\n');
    while (1) {
        if (getline(&buffer, &n, stdin) == -1)
            exit (0);
        verif_win();
    }
    return (0);
}