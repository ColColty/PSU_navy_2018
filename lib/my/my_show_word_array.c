/*
** EPITECH PROJECT, 2018
** show word array
** File description:
** SHOW WORD ARRAY
*/

#include "../../include/my.h"
#include "../../include/map.h"

int my_show_word_array(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        my_putstr(tab[i]);
        my_putchar('\n');
        i++;
    }
    return (0);
}
