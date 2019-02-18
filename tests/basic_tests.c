/*
** EPITECH PROJECT, 2018
** test.c
** File description:
** Tom
*/

#include <criterion/criterion.h>

Test(basic_tests, no_arguments)
{
    char * const argv[] = { "./navy", NULL };
    char * const env[] = { NULL };
    int ret_value = 0;

    ret_value = execve("./navy", argv, env);
    cr_assert_eq(ret_value, 84);
}

Test(basic_tests, arguments_bad_type)
{
    char * const argv[] = { "./navy", "1", "2", NULL };
    char * const env[] = { NULL };
    int ret_value = 0;

    ret_value = execve("./navy", argv, env);
    cr_assert_eq(ret_value, 84);
}

Test(basic_tests, arguments_good_and_bad_type)
{
    char * const argv[] = { "./navy", "pos1", "pos2", NULL };
    char * const env[] = { NULL };
    int ret_value = 0;

    ret_value = execve("./navy", argv, env);
    cr_assert_eq(ret_value, 84);
}

Test(basic_tests, arguments_NULL)
{
    char * const argv[] = { "./navy", "", "", NULL };
    char * const env[] = { NULL };
    int ret_value = 0;

    ret_value = execve("./navy", argv, env);
    cr_assert_eq(ret_value, 84);
}

Test(basic_tests, description)
{
    char * const argv[] = { "./navy", "-h", NULL };
    char * const env[] = { NULL };
    int ret_value = 0;

    ret_value = execve("./navy", argv, env);
    cr_assert_eq(ret_value, 84);
}