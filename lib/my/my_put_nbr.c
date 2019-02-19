/*
** EPITECH PROJECT, 2018
** MY PUT NBR
** File description:
** NO IDEA
*/

#include "../../include/my.h"

int test_null(int nl)
{
    if (nl == 0) {
        my_putchar(48);
    } else if (nl < 0) {
        my_putchar('-');
    }
    return (nl);
}

int my_put_nbr(int n)
{
    int div = 1000000000;
    int number;
    int the_eliminator = 0;
    long int n2 = n;

    n2 = test_null(n2);
    if (n2 < 0) {
        n2 *= -1;
    }
    while (div != 0) {
        number = (n2 / div) % 10;
        if (the_eliminator == 0 && number == 0) {
            the_eliminator = 0;
        } else {
            my_putchar(number + 48);
            the_eliminator = 1;
            }
        div /= 10;
    }
    return (0);
}
