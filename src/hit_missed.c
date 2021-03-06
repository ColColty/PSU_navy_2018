/*
** EPITECH PROJECT, 2019
** hit missed functions
** File description:
** functions to know if the player kit or missed the enemy
*/

#include "my.h"
#include "transmission.h"
#include "map.h"

void hit_or_loose(int sig, siginfo_t *info, void *context);

int recieve_hit_missed(transmissions_t *trans, connection_t *com,
info_t *player)
{
    struct sigaction sa = {0};
    int sig[2] = {10, 12};
    int ret = 0;

    my_putstr(trans->user_input);
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = hit_or_loose;
    for (int i = 0; i < 2; i++)
        if (sigaction(sig[i], &sa, NULL) == -1)
            return (-1);
    pause();
    ret = recupering_global(com, trans);
    if (ret == 12)
        player->map[TRANS(trans->user_input[1]) - 1]\
        [TRANS(trans->user_input[0]) * 2] = 'x';
    else if (ret == 10)
        player->map[TRANS(trans->user_input[1]) - 1]\
        [TRANS(trans->user_input[0]) * 2] = 'o';
    return (0);
}

int send_hit_missed(transmissions_t *trans, connection_t *com, info_t *player)
{
    usleep(1000);
    my_putstr(trans->attacant_input);
    return (touch_or_not(trans->attacant_input, player, com));
}

int send_attack(transmissions_t *trans, connection_t *com)
{
    my_putstr("\nattack: ");
    if (recup_entry(trans) == -1)
        return (-1);
    recupering_global(com, trans);
    if (send_signal(com, trans) == -1)
        return (-1);
    return (0);
}