/*
** EPITECH PROJECT, 2018
** ATOI
** File description:
** CONVERT CHAR IN INT
*/

#include "../../include/my.h"

int my_atoi(char *str)
{
    int number = 0;

    while (*str != '\0') {
        if (*str >= '0' && *str <= '9') {
            number *= 10;
            number += *str - '0';
        }
        else
            return (number);
        str++;
    }
    return (number);
}
