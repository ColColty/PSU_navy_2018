/*
** EPITECH PROJECT, 2019
** game loop
** File description:
** game loop
*/

#include "my.h"
#include "transmission.h"

int recup_entry(transmissions_t *trans)
{
    char *str = malloc(sizeof(char) * 3);
    int size = 0;

    while ((size = read(0, str, 128)) != 3)
        if (size == 0) {
            return (-1);
        }
    str[2] = '\0';
    trans->user_input = str;
    return (0);
}

int game_loop(connection_t *com, transmissions_t *trans, int player)
{
    if (player == 1) {
        send_attack(trans, com);
        recieve_hit_missed(trans);
        recieve_signal(com, trans);
        send_hit_missed(trans, com);
        return (game_loop(com, trans, player));
    } else if (player == 2) {
        recieve_signal(com, trans);
        send_hit_missed(trans, com);
        send_attack(trans, com);
        recieve_hit_missed(trans);
        return (game_loop(com, trans, player));
    }
    return (0);
}
