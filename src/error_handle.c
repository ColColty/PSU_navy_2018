/*
** EPITECH PROJECT, 2019
** error handle
** File description:
** error handle for the map
*/

#include "map.h"
#include "my.h"

int switch_line(char *buffer, int i)
{
    while(buffer[i] != '\n')
        i++;
    i += 1;
    if (buffer[i + 1] == '\0')
        return (i + 1);
    else
        return (i);
}

int check_double_point(char *buffer)
{
    int i = 0;

    while (buffer[i] != '\0') { 
        if (buffer[i + 1] == ':' && buffer[i + 4] == ':')
            i = switch_line(buffer, i);
        else
            return (-1);
    }
    return (0);
}

int check_nbr(int save, int choice, char *buffer, int i)
{
    int temp = 0;

    if (save >= 2 && save<= 5 && save != temp && choice == 0) {
                temp = save;
                i = switch_line(buffer, i);
            }
            else
                return (1);
    if (save + 1 >= 2 && save + 1 <= 5 && save + 1 != temp && choice == 1) {
                temp = save;
                i = switch_line(buffer, i);
            }
            else
                return (1);
    return (i);
}

int check_boat_size(char *buffer)
{
    int i = 0;
    int save = 0;

    while (buffer[i] != '\0') {
        if (buffer[i + 2] == buffer[i + 5]) {
            save = (((buffer[i + 6] - 48) - (buffer[i + 3] - 48)) + 1);
            my_put_nbr(save);
            if (check_nbr(save, 0, buffer, i) == 1)
                return (1);
        }
        else {
            save = ((buffer[i + 5] - buffer[i + 2]) + 1) - 65;
            if (check_nbr(save, 1, buffer, i) == 1)
                return (1);
        }
    }
    return (0);
}

int check_content(char *buffer)
{
    int i = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] >= 48 && buffer[i] <= 56
        || buffer[i] == ':' || buffer[i] >= 65 && buffer[i] <= 72 
        || buffer[i] == '\n')
            i++;
        else
            return (1);
    }
    return (i);
}

int main_error_gestion(char *pathfile)
{
    int fd = open(pathfile, O_RDONLY);
    char *buffer = NULL;

    if (fd == -1)
        return (1);
    buffer = malloc(sizeof(char) * 32);
    read(fd, buffer, 32);
    close(fd);
    buffer[32] = '\0';
    if (check_content(buffer) != 32)
        return (1);
    if (check_double_point(buffer) != 0)
        return (1);
    if (check_boat_size(buffer) != 0)
        return (1);
    free(buffer);
    return (0);
}