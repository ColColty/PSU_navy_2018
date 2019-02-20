/*
** EPITECH PROJECT, 2019
** transmission
** File description:
** transmission signal
*/

#include "my.h"
#include <stddef.h>
#include <signal.h>
#include <stdlib.h>

transmissions_t array[16][8] = {
    {'A', "01000001"},
    {'B', "01000010"},
    {'C', "01000011"},
    {'D', "01000100"},
    {'E', "01000101"},
    {'F', "01000110"},
    {'G', "01000111"},
    {'H', "01001000"},
    {'1', "00110001"},
    {'2', "00110010"},
    {'3', "00110011"},
    {'4', "00110100"},
    {'5', "00110101"},
    {'6', "00110110"},
    {'7', "00110111"},
    {'8', "00111000"}
};

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

void binary_interpreter(char *number)
{
    char letter;

    printf("%s\n", array[1]->binary_correspond);
    for (int i = 0; i < 16; i++) {
        if (!my_strcmp(number, array[i]->binary_correspond)) {
            #ifdef TESTS
                printf("%s equal to %s and the character is %c\n", number, array[i]->binary_correspond, array[i]->character);
            #endif
            letter = array[i]->character;
        }
    }
    #ifdef TESTS
        printf("The letter is %c\n", letter);
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