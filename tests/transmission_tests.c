/*
** EPITECH PROJECT, 2018
** TEST
** File description:
** test transmission
*/

#include <criterion/criterion.h>
#include "my.h"
#include "transmission.h"

char *signal_decoder(int sig, void *ptr, void *context);

void nothing_to_do(int sig, siginfo_t *info, void *context)
{
    return;
}

Test(transmission_tests, transmit_letter_a)
{
    int sigs[8] = {10, 12, 10, 10, 10, 10, 10, 12};
    char *ret;

    for (int i = 0; i < 8; i++)
        ret = signal_decoder(sigs[i], NULL, NULL);
    cr_assert_str_eq(ret, "01000001");
}

Test(transmission_tests, sending_a_signal_without_success)
{
    connection_t com = {1, 0, 9970};
    transmissions_t trans = {0, "01000001", "F1", "G3"};
    int ret = 0;

    ret = send_signal(&com, &trans);
    cr_assert_eq(ret, -1);
}

Test(transmission_tests, recieving_signals)
{
    connection_t com = {1, 0, 9970};
    transmissions_t trans = {0, "01000001", "F1", "G3"};

    recieve_signal(&com, &trans);
}

Test(transmission_tests, sending_letter_and_number)
{
    connection_t com = {1, 0, 9970};
    transmissions_t trans = {0, "01000001", "F1", "G3"};
    int ret = 0;
    int pid = 0;
    int subpid = 0;
    struct sigaction sa;
    int sigs[2] = {10, 12};

    com.pid = getpid();
    subpid = fork();
    if (subpid == 0) {
        sa.sa_flags = SA_SIGINFO;
        sa.sa_sigaction = nothing_to_do;
        for (int i = 0; i < 16; i++)
            for (int i = 0; i < 2; i++)
                sigaction(sigs[i], &sa, NULL);
    } else {
        com.attack_pid = subpid;
        ret = send_signal(&com, &trans);
    }
    cr_assert_eq(ret, 0);
}
