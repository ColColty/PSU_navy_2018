/*
** EPITECH PROJECT, 2019
** str cpy
** File description:
** cop an str
*/

#include <stddef.h>

char *my_strcpy(char *dest, char *src)
{
    int i = 0;

    if (src == NULL)
        return (NULL);
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}