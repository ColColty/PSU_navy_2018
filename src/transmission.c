/*
** EPITECH PROJECT, 2019
** transmission
** File description:
** transmission signal
*/

#include "my.h"
#include "transmission.h"

void get_attack_pid(int sig, siginfo_t *info, void *context);

int send_signal(connection_t *com, transmissions_t *trans)
{
    kill(com->attack_pid, SIGUSR1);
    if (signal_character_finder(com, trans->user_input[0]) == -1
    || signal_character_finder(com, trans->user_input[1]) == -1)
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
    if (i > 7) {
        number[i] = '\0';
        i = 0;
        binary_interpreter(number);
    }
    return (number);
}

char *recieve_signal(connection_t *com, transmissions_t *trans)
{
    struct sigaction sa = {0};
    int sig[2] = {10, 12};

    my_putstr("\nwaiting for enemy's attack...\n");
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = get_attack_pid;
    sigaction(SIGUSR1, &sa, NULL);
    sa.sa_sigaction = signal_decoder;
    pause();
    for (int i = 0; i < 16; i++) {
        kill(com->attack_pid, SIGUSR1);
        for (int k = 0; k < 2; k++)
            sigaction(sig[k], &sa, NULL);
        pause();
    }
    recupering_global(com, trans);
    return (trans->attacant_input);
}