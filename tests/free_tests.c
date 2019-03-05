/*
** EPITECH PROJECT, 2018
** TEST
** File description:
** test
*/

#include "my.h"
#include "map.h"
#include <criterion/criterion.h>

Test(free_tests, free_maps)
{
    player_t player;
    player.player_defender.map = create_the_map();
    player.player_enemy.map = create_the_map();
    int ret = -1;

    ret = free_everything(&player);
    cr_assert_eq(ret, 0);
}
