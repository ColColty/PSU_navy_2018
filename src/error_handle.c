/*
** EPITECH PROJECT, 2019
** error handle
** File description:
** error handle for the map
*/

#include "map.h"
#include "my.h"
#include "error_handle.h"
#include "transmission.h"

int check_boat(char *buffer, int i, int choice, save_t *save_s)
{
    int nbr = my_atoi_char(buffer[i + 6]) - my_atoi_char(buffer[i + 3]) + 1;
    int letter = (buffer[i + 5] - 65) - (buffer[i + 2] - 65) + 1;

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
        && my_atoi_char(buffer[i + 3]) >= 1
        && my_atoi_char(buffer[i + 3]) <= 8) {
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

int verif_file(char *buffer)
{
    int nbr = 2;
    int i = 0;

    while (buffer[i] != '\0') {
        if (my_atoi_char(buffer[i]) != nbr || buffer[i + 1] != ':'
        || buffer[i + 4] != ':')
            return (1);
        else {
            i += 8;
            nbr++;
        }
    }
    return (0);
}

int check_content(char *buffer)
{
    int i = 0;

    while (buffer[i] != '\0') {
        if ((buffer[i] > 48 && buffer[i] <= 56)
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
    save_t save_s;

    if (fd == -1)
        return (1);
    if ((buffer = malloc(sizeof(char) * 33)) == NULL) {
        close(fd);
        free(buffer);
        return (1);
    }
    read(fd, buffer, 32);
    close(fd);
    buffer[32] = '\0';
    if (check_content(buffer) != 32)
        return (1);
    if (verif_file(buffer) != 0)
        return (1);
    if (check_size_boat(buffer, &save_s) != 0)
        return (1);
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
