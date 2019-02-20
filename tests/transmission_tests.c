/*
** EPITECH PROJECT, 2018
** TEST
** File description:
** test transmission
*/

#include <criterion/criterion.h>
#include "my.h"

char *signal_decoder(int sig, void *ptr, void *context);

Test(transmission_tests, transmit_letter_a)
{
    int sigs[8] = {12, 10, 10, 10, 10, 10, 12, 10};
    char *ret;

    for (int i = 0; i < 8; i++)
        ret = signal_decoder(sigs[i], NULL, NULL);
    cr_assert_str_eq(ret, "01000001");
}

Test(transmission_tests, sending_a_signal)
{
    connection_t com = {1, 0, 9970};
    transmissions_t trans = {0, "01000001", "F1", "G3"};
    int ret = 0;

    ret = send_signal(&com, &trans);
    cr_assert_eq(ret, -1);
}

Test(transmission_tests, recieving_signals)
{
    recieve_signal();
}

