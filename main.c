/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "my.h"
#include "map.h"

int print_usage(void)
{
    my_putstr("USAGE:\n");
    my_putstr("\t./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tfirst_player_pid: onlyfor the 2nd player.");
    my_putstr(" pid of the first player.\n");
    my_putstr("\tnavy_positions: file representing the positions");
    my_putstr(" of the ships.\n");
    return (0);
}

int error_gestion(char *pathfile)
{
    int fd = open(pathfile, O_RDONLY);
    char *buffer = NULL;
    int i = 0;

    if (fd == -1)
        return (1);
    buffer = malloc(sizeof(char) * 32);
    read(fd, buffer, 32);
    close(fd);
    buffer[32] = '\0';
    while (buffer[i] != '\0') {
        if (buffer[i] >= 48 && buffer[i] <= 56
        || buffer[i] == ':' || buffer[i] >= 65 && buffer[i] <= 72 
        || buffer[i] == '\n')
            i++;
        else
            return (1);
    }
    free(buffer);
    return (0);
}

int error_handle(int argc, char * const * argv)
{
    if (argc < 2)
        return (1);
    if (argc == 2) {
        if(error_gestion(argv[1]) == 1)
            return (1);
    }
    else if (argc == 3) {
    }
    return (0);
}

int main(int argc, char * const * argv)
{
    int ret = 0;

    if (error_handle(argc, argv))
        return (84);
    if (!my_strcmp(argv[1], "-h")) {
        print_usage();
        return (0);
    }
    ret = navy(argc, argv);
    if (ret == 1)
        return (1);
    return (0);
}