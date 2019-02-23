/*
** EPITECH PROJECT, 2019
** game loop
** File description:
** game loop
*/

#include "my.h"
#include "transmission.h"

static int recup_entry(transmissions_t *trans)
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

static void hit_or_loose(int sig, siginfo_t *info, void *context)
{
    if (sig == 12)
        my_putstr(": hit\n");
    else if (sig == 10)
        my_putstr(": missed\n");
}

int p1_game_loop(connection_t *com, transmissions_t *trans)
{
    struct sigaction sa;
    int sig[2] = {10, 12};

    my_putstr("\nattack: ");
    if (recup_entry(trans) == -1)
        return (-1);
    recupering_global(com, trans);
    if (send_signal(com, trans) == -1) {
        return (-1);
    }
    my_putstr(trans->user_input);
    free(trans->user_input);
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = hit_or_loose;
    for (int i = 0; i < 2; i++)
        sigaction(sig[i], &sa, NULL);
    pause();
    recieve_signal(com, trans);
    usleep(1000);
    kill(com->attack_pid, SIGUSR2); // Remplacer par la detection de colision
    my_putstr(trans->attacant_input);
    my_putstr(": hit\n");
    return (p1_game_loop(com, trans));
}


int p2_game_loop(connection_t *com, transmissions_t *trans)
{
    struct sigaction sa;
    int sig[2] = {10, 12};

    recieve_signal(com, trans);
    usleep(1000);
    my_putstr(trans->attacant_input);
    my_putstr(": hit\n");
    kill(com->attack_pid, SIGUSR2); // Remplacer par la detection de colision
    my_putstr("\nattack: ");
    if (recup_entry(trans) == -1)
        return (-1);
    recupering_global(com, trans);
    if (send_signal(com, trans) == -1) {
        return (-1);
    }
    my_putstr(trans->user_input);
    free(trans->user_input);
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = hit_or_loose;
    for (int i = 0; i < 2; i++)
        sigaction(sig[i], &sa, NULL);
    pause();
    return (p2_game_loop(com, trans));
}