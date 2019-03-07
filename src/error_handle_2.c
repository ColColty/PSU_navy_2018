/*
** EPITECH PROJECT, 2018
** psu_sem2 (Workspace)
** File description:
** error_handle_2.c
*/

#include "map.h"
#include "my.h"
#include "error_handle.h"
#include "transmission.h"

int check_correct_size(char *buffer)
{
    int i = 0;

    while (buffer[i] != '\0') {
        if (buffer[i + 2] == buffer[i + 5]) {
            if (TRANS(buffer[i]) != TRANS(buffer[i + 6]) - TRANS(buffer[i + 3]) + 1) {
                my_put_nbr(TRANS(buffer[i + 6]) - TRANS(buffer[i + 3]) + 1);
                return (1);
            }
            else
                i += 8;
        }
        else
            if (TRANS(buffer[i]) != (TRANS(buffer[i + 5])) - TRANS(buffer[i + 2]) + 1) {
                my_put_nbr(buffer[i]) != TRANS(buffer[i + 5]) - TRANS(buffer[i + 2]) + 1;
                return (1);
            }
            else
                i += 8;
    }
    return (0);
}

int check_boat(char *buffer, int i, int choice, save_t *save_s)
{
    int nbr = TRANS(buffer[i + 6]) - TRANS(buffer[i + 3]) + 1;
    int letter = TRANS(buffer[i + 5]) - TRANS(buffer[i + 2]) + 1;

    if (choice == 1) {
        if (nbr == save_s->nbr_save)
            return (1);
        else {
            save_s->nbr_save = nbr;
            return (0);
        }
    }
    if (choice == 2) {
        if (letter == save_s->letter_save)
            return (1);
        else {
            save_s->letter_save = letter;
            return (0);
        }
    }
}

int check_size_boat(char *buffer, save_t *save_s)
{
    char save_letter;
    int i = 0;

    save_s->nbr_save = 1;
    save_s->letter_save = 1;
    while (buffer[i] != '\0')
        if (buffer[i + 2] >= 65 && buffer[i + 2] <= 72
        && TRANS(buffer[i + 3]) >= 1
        && TRANS(buffer[i + 3]) <= 8) {
            save_letter = buffer[i + 2];
            if (buffer[i + 5] == save_letter
            && check_boat(buffer, i, 1, save_s) == 0)
                i += 8;
            else if (buffer[i + 5] != save_letter
            && check_boat(buffer, i, 2, save_s) == 0)
                i += 8;
            else
                return (1);
        } else
            return (1);
    return (0);
}
