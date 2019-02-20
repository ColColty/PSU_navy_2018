/*
** EPITECH PROJECT, 2018
** MY_PUT_NBR_BASE
** File description:
** My_put_nbr changing base
*/

#include "../../include/my.h"
#include <signal.h>
#include <stddef.h>

static int completing(int i, connection_t *com)
{
    if (i < 8)
        for (int k = i; k < 8; k++) {
            if (kill(com->attack_pid, SIGUSR1) == -1)
                return (-1);
            printf("PD\n");
            usleep(1000);
        }
    return (0);
}

int my_send_nbr_base(int nb, char const *base, connection_t *com)
{
    int nb_base = 0;
    int base_size = my_strlen(base);
    int i = 0;

    if (base == NULL)
        return (0);
    for (i; nb != 0; i++) {
        nb_base = nb % base_size;
        if ((base[nb_base] % 2) == 0)
            if (kill(com->attack_pid, SIGUSR1) == -1)
                return (-1);
        else if ((base[nb_base] % 2) == 1)
            if (kill(com->attack_pid, SIGUSR2) == -1)
                return (-1);
        printf("%c\n", base[nb_base]);
        usleep(1000);
        printf("PD\n");
        nb /= base_size;
    }
    if (completing(i, com) == -1)
        return (-1);
    return (0);
}