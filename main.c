/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "my.h"
#include "transmission.h"

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

int main(int argc, char **argv)
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
        return (84);
    if (ret == 89)
        return (1);
    return (0);
}