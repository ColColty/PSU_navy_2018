/*
** EPITECH PROJECT, 2019
** signal
** File description:
** signal file to use only one global value
*/

#include "transmission.h"
#include "my.h"

volatile signal_t global_sig = {0, 0};

transmissions_t array[16][8] = {
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
}

void binary_interpreter(char *number)
{
    static int k = 0;

    for (int i = 0; i < 16; i++)
        if (!my_strcmp(number, array[i]->binary_correspond)) {
            global_sig.attacant_move[k++] = array[i]->character;
        }
    if (k > 1)
        k = 0;
}

void recupering_global(connection_t *connect, transmissions_t *trans)
{
    connect->attack_pid = (int) global_sig.pid_attacant;
    trans->attacant_input = (char *) global_sig.attacant_move;
}