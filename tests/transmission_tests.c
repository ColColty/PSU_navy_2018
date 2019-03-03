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

TestSuite(
    transmission_tests,
    .timeout = 2
);

Test(transmission_tests, transmit_letter_a)
{
    int sigs[8] = {10, 12, 10, 10, 10, 10, 10, 12};
    char *ret;

    for (int i = 0; i < 8; i++)
        ret = signal_decoder(sigs[i], NULL, NULL);
    cr_assert_str_eq(ret, "01000001");
}

Test(transmission_tests, connect_player1)
{
    connection_t com = {0, 9970};
    transmissions_t trans = {0, "01000001", "00", "00"};
    int p1_pid = 0;
    int p2_pid = 0;
    int ret = -1;

    p1_pid = fork();
    if (!p1_pid) {
        usleep(1000);
        kill(p1_pid, SIGUSR1);
        pause();
    } else {
        ret = connect_player1(&com, &trans);
    }
    cr_assert_eq(ret, 0);
}
