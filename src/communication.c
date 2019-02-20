/*
** EPITECH PROJECT, 2019
** game
** File description:
** game functions
*/

#include "my.h"
#include "transmission.h"

void get_attack_pid(int signum);

void connect_to_player(connection_t *connect, transmissions_t *trans)
{
    struct sigaction sa;

    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = get_attack_pid;
    sigaction(SIGUSR1, &sa, NULL);
    #ifdef TESTS
        printf("$$ Waiting for signal\n");
    #endif
    pause();
    recupering_global(connect, trans);
}

int connect_player1(connection_t *com, transmissions_t *trans)
{
    com->pid = getpid();
    my_putstr("my_pid: ");
    my_put_nbr(com->pid);
    my_putstr("\nWaiting for enemy connection...\n\n");
    connect_to_player(com, trans);
    #ifdef TESTS
        printf("$$ Signal recieved, sending confirmation\n");
    #endif
    if (kill(com->attack_pid, SIGUSR1) == -1)
        return (1);
    my_putstr("enemy connected\n");
    return (0);
}

int connect_player2(char * const *argv, connection_t *com, transmissions_t *trans)
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
    connect_to_player(com, trans);
    #ifdef TESTS
        printf("$$ Signal recieved !\n");
    #endif
    my_putstr("successfully connected\n");
    return (0);
}