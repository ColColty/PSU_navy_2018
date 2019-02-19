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

static int connected(int signum)
{
    if (signum == 10)
        communication.connected = 1;
    return (0);
}

void get_attack_pid(int sig, siginfo_t *info, void *context)
{
    communication.attack_pid = info->si_pid;
    connected(sig);
}

void player1(char * const * argv, connection_t *com)
{
    struct sigaction sa;

    communication.pid = getpid();
    my_putstr("my_pid: ");
    my_put_nbr(communication.pid);
    my_putstr("\nWaiting for enemy connection...\n\n");
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = get_attack_pid;
    sigaction(SIGUSR1, &sa, NULL);
    while (!communication.connected);
    kill(communication.attack_pid, SIGUSR1);
    my_putstr("enemy connected\n");
    com = &communication;
}

void player2(char * const * argv, connection_t *com)
{
    int pid = atoi(argv[1]);
    int mypid = getpid();
    struct sigaction sa;

    my_putstr("my_pid: ");
    my_put_nbr(mypid);
    my_putchar('\n');
    kill(pid, SIGUSR1);
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = get_attack_pid;
    sigaction(SIGUSR1, &sa, NULL);
    while (!communication.connected);
    my_putstr("successfully connected\n");
    com = &communication;
    return (0);
}