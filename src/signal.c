/*
** EPITECH PROJECT, 2019
** signal
** File description:
** signal file to use only one global value
*/

#include "transmission.h"
#include "my.h"

volatile signal_t global_sig = {0, "00", 0};

transmissions_t inputs_binaries[16][8] = {
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

void get_attack_pid(int sig, siginfo_t *info, void *context)
{
    global_sig.pid_attacant = info->si_pid;
    global_sig.signal_recieved = sig;
}

void binary_interpreter(char *number)
{
    static int k = 0;

    for (int i = 0; i < 16; i++)
        if (!my_strcmp(number, inputs_binaries[i]->binary_correspond))
            global_sig.attacant_move[k++] = inputs_binaries[i]->character;
    if (k > 1) {
        global_sig.attacant_move[2] = '\0';
        k = 0;
    }
}

int recupering_global(connection_t *connect, transmissions_t *trans)
{
    connect->attack_pid = (int) global_sig.pid_attacant;
    trans->attacant_input = (char *) global_sig.attacant_move;
    return (global_sig.signal_recieved);
}

void hit_or_loose(int sig, siginfo_t *info, void *context)
{
    global_sig.signal_recieved = sig;
    if (sig == 12)
        my_putstr(": hit\n");
    else if (sig == 10)
        my_putstr(": missed\n");
}
