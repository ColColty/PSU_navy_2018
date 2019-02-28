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

    while ((size = read(0, str, 3)) != 3) {
        if (size == 0)
            return (-1);
        my_putstr("attack: ");
    }
    str[2] = '\0';
    trans->user_input = str;
    return (0);
}

int game_loop_p1(connection_t *com, transmissions_t *trans,  player_t *player)
{
    if (send_attack(trans, com) == -1)
        return (-1);
    if (recieve_hit_missed(trans) == -1)
        return (-1);
    recieve_signal(com, trans);
    send_hit_missed(trans, com, &player->player_defender);
    print_hud(player);
    free(trans->user_input);
    if (game_condition(&player->player_defender))
        return (game_loop_p1(com, trans, player));
    return (0);
}

int game_loop_p2(connection_t *com, transmissions_t *trans,  player_t *player)
{
    recieve_signal(com, trans);
    send_hit_missed(trans, com, &player->player_defender);
    if (send_attack(trans, com) == -1)
        return (-1);
    if (recieve_hit_missed(trans) == -1)
        return (-1);
    print_hud(player);
    free(trans->user_input);
    if (game_condition(&player->player_defender))
        return (game_loop_p2(com, trans, player));
    return (0);
}