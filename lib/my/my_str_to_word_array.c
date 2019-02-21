/*
** EPITECH PROJECT, 2018
** my_str_to_word_array
** File description:
** split a str into array of words
*/

#include "../../include/my.h"
#include "../../include/map.h"

int count_words(char *str)
{
    int i = 0;
    int words = 0;

    while (str[i] != '\0') {
        if (str[i] == ' ' || str[i] == '\0')
            words++;
        i++;
    }
    return (words + 1);
}

int my_word_size(char *str, int index)
{
    int j = 0;

    while (str[index] != '\n' && str[index] != '\0') {
        j += 1;
        index += 1;
    }
    return (j);
}

char **my_str_to_word_array(char *str)
{
    char **tab = NULL;
    int i = 0;
    int j = 0;
    int k = 0;

    tab = malloc(sizeof(char *) * (count_words(str)));
    while (i < count_words(str)) {
        tab[i] = malloc(sizeof(char) * (my_word_size(str, k) + 2));
        while (str[k] != ' ' && str[k] != '\0' && str[k] != '\n')
            tab[i][j++] = str[k++];
        tab[i][j] = '\0';
        i++;
        j = 0;
        k += 1;
    }
    tab[i] = NULL;
    return (tab);
}
