/*
** EPITECH PROJECT, 2019
** transmission
** File description:
** transmission signal
*/

#include "my.h"
#include "transmission.h"

void get_attack_pid(int sig, siginfo_t *info, void *context);

transmissions_t inputs_binaries_2[16][8] = {
    {'A', "01000001", NULL, NULL},
    {'B', "01000010", NULL, NULL},
    {'C', "01000011", NULL, NULL},
    {'D', "01000100", NULL, NULL},
    {'E', "01000101", NULL, NULL},
    {'F', "01000110", NULL, NULL},
    {'G', "01000111", NULL, NULL},
    {'H', "01001000", NULL, NULL},
    {'1', "00110001", NULL, NULL},
    {'2', "00110010", NULL, NULL},
    {'3', "00110011", NULL, NULL},
    {'4', "00110100", NULL, NULL},
    {'5', "00110101", NULL, NULL},
    {'6', "00110110", NULL, NULL},
    {'7', "00110111", NULL, NULL},
    {'8', "00111000", NULL, NULL}
};

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

static int signal_send_character(connection_t *com, int i)
{
    struct sigaction sa = {0};
    int ret = 0;

    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = get_attack_pid;
    for (int k = 0; k < 8; k++) {
        sigaction(SIGUSR1, &sa, NULL);
        if ((ret = usleep(1000000)) != -1)
            k--;
        if (inputs_binaries_2[i]->binary_correspond[k] == '0') {
            if (kill(com->attack_pid, SIGUSR1) == -1)
                return (-1);
        } else if (inputs_binaries_2[i]->binary_correspond[k] == '1')
            if (kill(com->attack_pid, SIGUSR2) == -1)
                return (-1);
    }
    return (0);
}

int signal_character_finder(connection_t *com, char character)
{
    for (int i = 0; i < 16; i++)
        if (character == inputs_binaries_2[i]->character)
            if (signal_send_character(com, i) == -1)
                return (-1);
    return (0);
}
