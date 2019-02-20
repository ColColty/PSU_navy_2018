/*
** EPITECH PROJECT, 2018
** MY.h
** File description:
** Write a library that includes all the prototyped functions
*/

#ifndef MY_H_
#define MY_H_

#define INPUT(value) ((value > 57) ? (value - 48) : (value -65))

typedef struct {
    int connected;
    int pid;
    int attack_pid;
} connection_t;

typedef struct {
    char character;
    char *binary_correspond;
    char *user_input;
} transmissions_t;

void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char *s2);
int my_show_word_array(char **tab);
int my_put_nbr(int nb);
int my_send_nbr_base(int nb, char const *base, connection_t *com);

int navy(int argc, char * const *argv);
int connectplayer1(char * const * argv, connection_t *com);
int connectplayer2(char * const * argv, connection_t *com);


#endif