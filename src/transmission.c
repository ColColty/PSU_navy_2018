/*
** EPITECH PROJECT, 2019
** transmission
** File description:
** transmission signal
*/

#include "my.h"
#include "transmission.h"

int send_signal(connection_t *com, transmissions_t *game)
{
    if (my_send_nbr_base(game->user_input[0], "01", com) == -1)
        return (-1);
    if (my_send_nbr_base(game->user_input[1], "01", com) == -1)
        return (-1);
    return (0);
}

char *signal_decoder(int sig, siginfo_t *info, void *context)
{
    static char number[8];
    static int i = 0;
    int nb_binary = 0;

    if (sig == 10)
        number[i++] = '0';
    else if (sig == 12)
        number[i++] = '1';
    number[i] = '\0';
    printf("%s\n", number);
    if (i > 7) {
        number[i] = '\0';
        my_revstr(number);
        i = 0;
        binary_interpreter(number);
    }
    return (number);
}

void recieve_signal(void)
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