/*
** EPITECH PROJECT, 2018
** MY.h
** File description:
** Write a library that includes all the prototyped functions
*/

#ifndef MY_H_
#define MY_H_

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct {
    int connected;
    int pid;
    int attack_pid;
} connection_t;

typedef struct {
    char character;
    char *binary_correspond;
    char *user_input;
    char *attacant_input;
} transmissions_t;

void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char *s2);
int my_show_word_array(char **tab);
int my_put_nbr(int nb);
int my_send_nbr_base(int nb, char const *base, connection_t *com);
int my_atoi(char *src);
int my_revstr(char *src);

int navy(int argc, char * const *argv);
int connect_player1(connection_t *com, transmissions_t *trans);
int connect_player2(char * const * argv, connection_t *com,
transmissions_t *trans);
void recieve_signal(connection_t *com, transmissions_t *game);
void send_signal(connection_t *com, transmissions_t *game);
void binary_interpreter(char *number);
void recupering_global(connection_t *connect, transmissions_t *trans);

#endif