/*
** EPITECH PROJECT, 2019
** Game condition
** File description:
** WIning or losing condition
*/

void game_condition(info_t *player)
{
    for (int i = 0; player.map[i] != NULL; i++) {
        for (int k = 0; player.map[i][k] != '\0'; k++) {
            if (player.map[i][k] >= 1 && player.map[i][k] <= 9)
                return (0);
        }
    }
    my_putstr("I won");
    // Send a signal to the enemy 
}