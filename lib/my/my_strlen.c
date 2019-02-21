/*
** EPITECH PROJECT, 2018
** MY_STRLEN
** File description:
** Display how many characters in my string
*/

#include <stddef.h>

int my_strlen(char const *str)
{
    int count = 0;

    if (str == NULL)
        return (0);
    for (count; str[count] != '\0'; count++);
    return (count);
}
