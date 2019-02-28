/*
** EPITECH PROJECT, 2019
** error handle
** File description:
** error handle for the map
*/

#include "map.h"
#include "my.h"
#include "transmission.h"

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

int check_content(char *buffer)
{
    int i = 0;

    while (buffer[i] != '\0') {
        if ((buffer[i] >= 48 && buffer[i] <= 56)
        || buffer[i] == ':' || (buffer[i] >= 65 && buffer[i] <= 72)
        || buffer[i] == '\n')
            i++;
        else
            return (-1);
    }
    return (i);
}

int main_error_gestion(char *pathfile)
{
    int fd = open(pathfile, O_RDONLY);
    char *buffer = NULL;

    if (fd == -1)
        return (1);
    if ((buffer = malloc(sizeof(char) * 32)) == NULL) {
        close(fd);
        free(buffer);
        return (1);
    }
    read(fd, buffer, 32);
    close(fd);
    buffer[32] = '\0';
    if (check_content(buffer) != 32) {
        free(buffer);
        return (1);
    }
    if (check_double_point(buffer)) {
        free(buffer);
        return (1);
    }
    free(buffer);
    return (0);
}


int error_handle(int argc, char **argv)
{
    if (argc != 2 && argc != 3)
        return (1);
    else if (argc == 2) {
        if (main_error_gestion(argv[1]))
            return (1);
    } else if (argc == 3) {
        for (int i = 0; argv[1][i] != '\0'; i++)
            if (argv[1][i] > 57 || argv[1][i] < 48)
                return (1);
        if (main_error_gestion(argv[2]))
            return (1);
        if (kill(my_atoi(argv[1]), SIGCONT) == -1)
            return (1);
    }
    return (0);
}