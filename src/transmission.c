/*
** EPITECH PROJECT, 2019
** transmission
** File description:
** transmission signal
*/

#include "my.h"

void send_signal(connection_t *com, game_t *game)
{
    int binary = 0;

    binary = my_send_nbr_base(game->user_input[0], "01", com);
    #ifdef TESTS
        printf("$$ Signal for letter was send ! Binary: %d\n", binary);
    #endif
    binary = my_send_nbr_base(game->user_input[1], "01", com);
    #ifdef TESTS
        printf("$$ Signal for number was sended ! Binary %d\n", binary);
    #endif
}

static int signal_decoder(connection_t *com, game_t *game)
{

}

void recieve_signal(connection_t *com, game_t *game)
{

}