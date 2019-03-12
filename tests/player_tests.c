/*
** EPITECH PROJECT, 2018
** TEST
** File description:
** test
*/

#include "map.h"
#include "my.h"
#include <criterion/criterion.h>

Test(player_tests, adding_boats_file_with_return)
{
    info_t player;
    char *buffer = "2:C1:C2\n3:D4:F4\n4:B5:B8\n5:D7:H7\n";
    player.map = create_the_map();
    int ret = 1;

    ret = gestion_first_player(&player, buffer);
    cr_assert_eq(ret, 0);
    for (int i = 0; player.map[i] != '\0'; i++)
        free(player.map[i]);
    free(player.map);
}

Test(player_tests, adding_boats_file_without_return)
{
    info_t player;
    char *buffer = "2:C1:C2\n3:D4:F4\n4:B5:B8\n5:D7:H7";
    player.map = create_the_map();
    int ret = 1;

    ret = gestion_first_player(&player, buffer);
    cr_assert_eq(ret, 0);
    for (int i = 0; player.map[i] != '\0'; i++)
        free(player.map[i]);
    free(player.map);
}

Test(player_tests, recover_ship_pos_and_setting_to_player)
{
    char *file = "pos1";
    player_t player;
    int ret = 1;

    ret = recover_ship_position(file, &player);
    cr_assert_eq(ret, 0);
    free_everything(&player);
}

Test(player_tests, recover_ship_pos_and_setting_to_player_bad_file)
{
    char *file = "data";
    player_t player;
    int ret = 1;

    ret = recover_ship_position(file, &player);
    cr_assert_eq(ret, -1);
}