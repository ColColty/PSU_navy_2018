/*
** EPITECH PROJECT, 2019
** signal
** File description:
** signal
*/

#ifndef TRANSMISSION_H
#define TRANSMISSION_H

#include <signal.h>
#include <sys/types.h>

typedef struct signal_s {
    int pid_attacant;
    char attacant_move[3];
    int signal_recieved;
} signal_t;

#endif /* !SIGNAL_H_ */
