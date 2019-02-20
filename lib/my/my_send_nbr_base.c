/*
** EPITECH PROJECT, 2018
** MY_PUT_NBR_BASE
** File description:
** My_put_nbr changing base
*/

#include "../../include/my.h"
#include <signal.h>
#include <stddef.h>

int my_send_nbr_base(int nb, char const *base, connection_t *com)
{
    int nb_base = 0;
    int base_size = my_strlen(base);
    int i = 0;
    int number = 0;
    unsigned int usecs = 1000;

    if (base == NULL)
        return (0);
    while (nb != 0) {
        nb_base = nb % base_size;
        if ((base[nb_base] % 2) == 0)
            kill(com->attack_pid, SIGUSR1);
        else if ((base[nb_base] % 2) == 1)
            kill(com->attack_pid, SIGUSR2);
        usleep(usecs);
        nb /= base_size;
    }
    return (number);
}