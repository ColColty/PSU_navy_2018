/*
** EPITECH PROJECT, 2019
** map.c
** File description:
** Draw the map
*/

#include "my.h"
#include "map.h"

int print_map(char *pathfile)
{
    int fd = 0;
    char *buffer = NULL;

    if (fd = open(pathfile, O_RDONLY) != 1) {
        while (read(fd, buffer, 7) != 0)
            my_putchar('X');
    }
    else
    {
        return (84);
    }
}