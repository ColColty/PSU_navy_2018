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
    return (0);
}

void connect_to_player(void)
{
    struct sigaction sa;

    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = get_attack_pid;
    sigaction(SIGUSR1, &sa, NULL);
    #ifdef TESTS
        printf("$$ Waiting for signal\n");
    #endif
    pause();
}

int connect_player1(connection_t *com)
{
    communication.pid = getpid();
    my_putstr("my_pid: ");
    my_put_nbr(communication.pid);
    my_putstr("\nWaiting for enemy connection...\n\n");
    connect_to_player();
    #ifdef TESTS
        printf("$$ Signal recieved, sending confirmation\n");
    #endif
    if (kill(communication.attack_pid, SIGUSR1) == -1)
        return (1);
    my_putstr("enemy connected\n");
    com->attack_pid = communication.attack_pid;
    return (0);
}

int connect_player2(char * const * argv, connection_t *com)
{
    com->attack_pid = my_atoi(argv[1]);
    com->pid = getpid();
    my_putstr("my_pid: ");
    my_put_nbr(com->pid);
    my_putchar('\n');
    #ifdef TESTS
        printf("$$ Sending signal for connection\n");
    #endif
    if (kill(com->attack_pid, SIGUSR1) == -1)
        return (1);
    connect_to_player();
    #ifdef TESTS
        printf("$$ Signal recieved !\n");
    #endif
    my_putstr("successfully connected\n");
    com->attack_pid = communication.attack_pid;
    return (0);
}