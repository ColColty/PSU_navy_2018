/*
** EPITECH PROJECT, 2019
** game loop
** File description:
** game loop
*/

#include "my.h"
#include "transmission.h"

int verif_input(char *str)
{
    if ((str[1] <= 48 || str[1] > 56) || (str[0] < 65 || str[0] > 72))
        return (1);
    return (0);
}

int recup_entry(transmissions_t *trans)
{
    char *str = malloc(sizeof(char) * 3);
    int size = 0;

    while ((size = read(0, str, 3)) < 3) {
        if (size == 0) {
            free(str);
            return (-1);
        }
        my_putstr("attack: ");
    }
    str[2] = '\0';
    if (verif_input(str)) {
        free(str);
        my_putstr("attack: ");
        return (recup_entry(trans));
    }
    trans->user_input = str;
    return (0);
}

int game_loop_p1(connection_t *com, transmissions_t *trans,  player_t *player)
{
    int ret = 0;

    if (send_attack(trans, com) == -1)
        return (3);
    if (recieve_hit_missed(trans, com, &player->player_enemy) == -1)
        return (-1);
    recieve_signal(com, trans);
    send_hit_missed(trans, com, &player->player_defender);
    print_hud(player);
    free(trans->user_input);
    ret = game_condition(player, com);
    if (ret == 0)
        return (game_loop_p1(com, trans, player));
    return (ret);
}

int game_loop_p2(connection_t *com, transmissions_t *trans,  player_t *player)
{
    int ret = 0;

    recieve_signal(com, trans);
    send_hit_missed(trans, com, &player->player_defender);
    if (send_attack(trans, com) == -1)
        return (3);
    if (recieve_hit_missed(trans, com, &player->player_enemy) == -1)
        return (-1);
    print_hud(player);
    free(trans->user_input);
    ret = game_condition(player, com);
    if (ret == 0)
        return (game_loop_p2(com, trans, player));
    return (ret);
}