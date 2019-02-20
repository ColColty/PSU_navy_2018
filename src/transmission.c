/*
** EPITECH PROJECT, 2019
** transmission
** File description:
** transmission signal
*/

#include "my.h"
#include "transmission.h"

void send_signal(connection_t *com, transmissions_t *game)
{
    my_send_nbr_base(game->user_input[0], "01", com);
    #ifdef TESTS
        printf("$$ Signal for letter %c was send !\n", game->user_input[0]);
    #endif
    my_send_nbr_base(game->user_input[1], "01", com);
    #ifdef TESTS
        printf("$$ Signal for number %c was sended !\n", game->user_input[1]);
    #endif
}

void signal_decoder(int sig, siginfo_t *info, void *context)
{
    static char number[8];
    static int i = 0;
    int nb_binary = 0;

    if (sig == 10)
        number[i++] = '0';
    else if (sig == 12)
        number[i++] = '1';
    #ifdef TESTS
        number[i] = '\0';
        printf("$$ Number recieved ! Adding : %s\n", number);
    #endif
    if (i > 7) {
        number[i] = '\0';
        my_revstr(number);
        i = 0;
        binary_interpreter(number);
    }
}

void recieve_signal(connection_t *com, transmissions_t *game)
{
    struct sigaction sa;
    int sig[2] = {10, 12};

    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = signal_decoder;
    for (int i = 0; i < 16; i++) {
        for (int k = 0; k < 2; k++)
            sigaction(sig[k], &sa, NULL);
        pause();
    }
}