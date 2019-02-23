/*
** EPITECH PROJECT, 2019
** hit missed functions
** File description:
** functions to know if the player kit or missed the enemy
*/

#include "my.h"
#include "transmission.h"

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
    free(trans->user_input);
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = hit_or_loose;
    for (int i = 0; i < 2; i++)
        if (sigaction(sig[i], &sa, NULL) == -1)
            return (-1);
    pause();
    return (0);
}

void send_hit_missed(transmissions_t *trans, connection_t *com)
{
    usleep(1000);
    my_putstr(trans->attacant_input);
    my_putstr(": hit\n");
    kill(com->attack_pid, SIGUSR2); // Remplacer par la detection de colision
}

int send_attack(transmissions_t *trans, connection_t *com)
{
    my_putstr("\nattack: ");
    if (recup_entry(trans) == -1)
        return (-1);
    recupering_global(com, trans);
    if (send_signal(com, trans) == -1) {
        return (-1);
    }
    return (0);
}