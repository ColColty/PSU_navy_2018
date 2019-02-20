/*
** EPITECH PROJECT, 2018
** MY.h
** File description:
** Write a library that includes all the prototyped functions
*/

#ifndef MY_H_
#define MY_H_

#define INPUT(value) ((value > 57) ? (value - 48) : (value -65))

#define A "01000001"
#define B "01000010"
#define C "01000011"
#define D "01000100"
#define E "01000101"
#define F "01000110"
#define G "01000111"
#define H "01001000"

typedef struct {
    int connected;
    int pid;
    int attack_pid;
} connection_t;

void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_show_word_array(char **tab);
int my_put_nbr(int nb);

int navy(int argc, char * const *argv);
void player1(char * const * argv, connection_t *com);
void player2(char * const * argv, connection_t *com);


#endif