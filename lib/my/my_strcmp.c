/*
** EPITECH PROJECT, 2018
** MY_STRCMP
** File description:
** Reproduce the behavior of strcmp
*/

#include <stddef.h>

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (s1 == NULL || s2 == NULL)
        return (84);
    for (i; s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]; i++);
    if (s1[i] < s2[i])
        return (-1);
    else if (s1[i] > s2[i])
        return (1);
    return (0);
}