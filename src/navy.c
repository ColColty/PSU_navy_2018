/*
** EPITECH PROJECT, 2019
** navy
** File description:
** navy
*/

#include "my.h"
#include "map.h"

int verif_win(void)
{
    printf("BONJOUR");
}
int navy(int argc, char * const *argv)
{
    connection_t com;
    char *buffer = NULL;
    position_t position;
    size_t n = 0;

    if (argc == 2) {
        player1(argv, &com);
        recover_ship_position(argv[1]);
    }
    else if (argc == 3) {
        player2(argv, &com);
        recover_ship_position(argv[2]);
    }
    while (1) {
        if (getline(&buffer, &n, stdin) == -1)
            exit (0);
        verif_win();
        }
    return (0);
}