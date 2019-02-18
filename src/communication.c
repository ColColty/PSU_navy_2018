/*
** EPITECH PROJECT, 2019
** communication
** File description:
** communication
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void sighandler(int signum)
{
    printf("Caught signal %d, coming out...\n", signum);
    exit(1);
}

int player1(void)
{
    int signal_id = 0;

    signal(signal_id, sighandler);
    printf("%d\n", getpid());
    while(1) {
        printf("Going to sleep for two second...\n");
        sleep(2);
    }
    return (0);
}

int player2(void)
{
    int pid = 0;
    char *buff = NULL;
    size_t n;

    getline(&buff, &n, stdin);
    pid = atoi(buff);
    kill(pid, SIGSEGV);
    return (0);
}

int main (int argc, char **argv)
{
    if (argv[1][0] == '1')
        player1();
    else if (argv[1][0] == '2')
        player2();
    return(0);
}
