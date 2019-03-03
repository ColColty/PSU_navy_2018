/*
** EPITECH PROJECT, 2019
** hit missed functions
** File description:
** functions to know if the player kit or missed the enemy
*/

#include "my.h"
#include "transmission.h"
#include "map.h"

static void hit_or_loose(int sig, siginfo_t *info, void *context)
{
    if (sig == 12)
        my_putstr(": hit\n");
    else if (sig == 10)
        my_putstr(": missed\n");
}

int recieve_hit_missed(transmissions_t *trans)
{
    struct sigaction sa;
    int sig[2] = {10, 12};

    my_putstr(trans->user_input);
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = hit_or_loose;
    for (int i = 0; i < 2; i++)
        if (sigaction(sig[i], &sa, NULL) == -1)
            return (-1);
    pause();
    return (0);
}

int send_hit_missed(transmissions_t *trans, connection_t *com, info_t *player)
{
    usleep(100000);
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