/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

int error_handle(int argc, char * const * argv)
{
    if (argc != 1)
        return (1);
    return (0);
}

int main(int argc, char * const * argv)
{
    if (error_handle(argc, argv))
        return (84);
    navy();
    return (0);
}