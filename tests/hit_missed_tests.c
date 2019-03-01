/*
** EPITECH PROJECT, 2018
** TEST
** File description:
** test
*/

#include "my.h"
#include "map.h"
#include "transmission.h"
#include <criterion/criterion.h>

Test(touch_tests, send_touch_bad_pid_no_boats)
{
    transmissions_t trans;
    connection_t com;
    info_t player;
    int ret = -2;

    player.map = create_the_map();
    trans.attacant_input = "B1";
    com.attack_pid = 999999;
    ret = touch_or_not(trans.attacant_input, &player, &com);
    cr_assert_eq(ret, -1);
}

Test(touch_tests, send_touch_good_pid_no_boats)
{
    transmissions_t trans;
    connection_t com;
    info_t player;
    int ret = -2;
    int pid = 0;

    pid = fork();
    if (!pid)
        usleep(10000000);
    else {
        player.map = create_the_map();
        trans.attacant_input = "B1";
        com.attack_pid = pid;
        ret = send_hit_missed(&trans, &com, &player);
        kill(pid, SIGQUIT);
    }
    cr_assert_eq(ret, 1);
}
