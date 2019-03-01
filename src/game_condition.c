/*
** EPITECH PROJECT, 2019
** Game condition
** File description:
** WIning or losing condition
*/

#include "map.h"
#include "my.h"
#include "transmission.h"

void win_loose_sig(int sig, siginfo_t *info, void *context)
{
    if (sig == 12)
        my_putstr("Enemy won");
}

int touch_or_not(char *coor, info_t *player, connection_t *com)
{
    if (player->map[TRANS(coor[1]) - 1][TRANS(coor[0]) * 2] >= '1'
    && player->map[TRANS(coor[1]) - 1][TRANS(coor[0]) * 2] <= '9') {
        my_putstr(": hit\n");
        if (kill(com->attack_pid, SIGUSR2) == -1)
            return (-1);
        return (0);
    }
    my_putstr(": missed\n");
    if (kill(com->attack_pid, SIGUSR1) == -1)
        return (-1);
    return (1);
}

int game_condition(info_t *player, connection_t *com)
{
    struct sigaction sa;

    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = win_loose_sig;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    for (int i = 0; player->map[i] != NULL; i++)
        for (int k = 0; player->map[i][k] != '\0'; k++)
            if (player->map[i][k] >= '1' && player->map[i][k] <= '9') {
                kill(com->attack_pid, SIGUSR1);
                return (1);
            }
    my_putstr("I won");
    kill(com->attack_pid, SIGUSR2);
    return (0);
}