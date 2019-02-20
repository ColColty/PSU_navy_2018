/*
** EPITECH PROJECT, 2019
** game
** File description:
** game functions
*/

#include "my.h"
#include <signal.h>
#include <stddef.h>
#include <stdio.h>

extern connection_t communication = {0, -1};

void get_attack_pid(int sig, siginfo_t *info, void *context)
{
    communication.attack_pid = info->si_pid;
    if (sig == 10)
        communication.connected = 1;
    return (0);
}

void connect_to_player(void)
{
    struct sigaction sa;

    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = get_attack_pid;
    sigaction(SIGUSR1, &sa, NULL);
    while (!communication.connected);
}

void player1(char * const * argv, connection_t *com)
{

    communication.pid = getpid();
    my_putstr("my_pid: ");
    my_put_nbr(communication.pid);
    my_putstr("\nWaiting for enemy connection...\n\n");
    connect_to_player();
    kill(communication.attack_pid, SIGUSR1);
    my_putstr("enemy connected\n");
    com = &communication;
}

void player2(char * const * argv, connection_t *com)
{
    com->attack_pid = my_atoi(argv[1]);
    com->pid = getpid();
    my_putstr("my_pid: ");
    my_put_nbr(com->pid);
    my_putchar('\n');
    kill(com->attack_pid, SIGUSR1);
    connect_to_player();
    my_putstr("successfully connected\n");
    com = &communication;
}