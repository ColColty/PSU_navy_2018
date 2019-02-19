/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** put number
*/

#include "../../include/my.h"

int negatif(int chiffre)
{
    if (chiffre < 0) {
        my_putchar('-');
        return (1);
    }
    else
        return (0);
}

int my_put_chiffre(long int chiffre)
{
    if (chiffre >= 10) {
        my_put_nbr(chiffre/10);
    }
    chiffre = chiffre % 10 + 48;
    my_putchar(chiffre);
    return (0);
}

int my_put_nbr(int nb)
{
    long int chiffre;
    int test;

    chiffre = nb;
    test = negatif(chiffre);
    if (test == 1)
        chiffre = -chiffre;
    if (chiffre >= 10) {
        my_put_chiffre(chiffre/10);
    }
    chiffre = chiffre % 10 + 48;
    my_putchar(chiffre);
    return (0);
}
