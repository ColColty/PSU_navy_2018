/*
** EPITECH PROJECT, 2019
** save position
** File description:
** save the position for the boat 
*/

#include "include/my.h"
#include "include/map.h"

void save_position(char **tab, char *pos)
{
    int fd = open(pos, O_RDONLY);
    char *buffer = NULL;

    if (fd == -1)
        return(84);
    buffer = malloc(sizeof(char) * 32);
    read(fd, buffer, 32);
    buffer[33] = '\0';
    close(fd);
}

int main_save_position(position_t *position, int player, char *pos)
{
    if (player == 1)
        save_position(&position->tab_position_one, pos);
    else if (player == 2)
        save_position(&position->tab_position_two, pos);
    return (0);
}