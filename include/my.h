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
#include "map.h"

typedef struct {
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
int my_atoi(char *src);
int my_revstr(char *src);
char *my_strcpy(char *dest, char *src);

int navy(int argc, char * const *argv);
int connect_player1(connection_t *com, transmissions_t *trans);
int connect_player2(connection_t *com, transmissions_t *trans);
char *recieve_signal(connection_t *com, transmissions_t *trans);
int send_signal(connection_t *com, transmissions_t *game);
void binary_interpreter(char *number);
int recupering_global(connection_t *connect, transmissions_t *trans);
int signal_character_finder(connection_t *com, char character);
int game_loop_p2(connection_t *com, transmissions_t *trans, player_t *player);
int game_loop_p1(connection_t *com, transmissions_t *trans,  player_t *player);
int recup_entry(transmissions_t *trans);
int send_attack(transmissions_t *trans, connection_t *com);
int send_hit_missed(transmissions_t *trans, connection_t *com, info_t *player);
int recieve_hit_missed(transmissions_t *trans, connection_t *com);
int touch_or_not(char *input, info_t *player, connection_t *com);
int game_condition(info_t *player);
int free_everything(player_t *player);
int error_handle(int argc, char **argv);

#endif