/*
** EPITECH PROJECT, 2018
** TEST
** File description:
** test
*/

#include "my.h"
#include <criterion/criterion.h>

Test(basic_tests, test_less_arguments)
{
    int argc = 1;
    char *argv[] = {"./navy", NULL };
    int ret = -1;

    ret = error_handle(argc, argv);
    cr_assert_eq(ret, 1);
}

Test(basic_tests, test_too_much_arguments)
{
    int argc = 4;
    char *argv[] = {"./navy", "1", "2", "3", NULL};
    int ret = -1;

    ret = error_handle(argc, argv);
    cr_assert_eq(ret, 1);
}

Test(basic_tests, test_arguments_for_p1_good_file)
{
    int argc = 2;
    char *argv[] = {"./navy", "pos1", NULL};
    int ret = -1;

    ret = error_handle(argc, argv);
    cr_assert_eq(ret, 0);
}

Test(basic_tests, test_arguments_for_p1_bad_file)
{
    int argc = 2;
    char *argv[] = {"./navy", "data", NULL};
    int ret = -1;

    ret = error_handle(argc, argv);
    cr_assert_eq(ret, 1);
}

Test(basic_tests, test_arguments_for_p2_bad_file)
{
    int argc = 3;
    char *argv[] = {"./navy", "", "data", NULL};
    int ret = -1;

    ret = error_handle(argc, argv);
    cr_assert_eq(ret, 1);
}

Test(basic_tests, test_arguments_p2_bad_pid)
{
    int argc = 3;
    char *argv[] = {"./navy", "9999999", "pos2", NULL};
    int ret = -1;

    ret = error_handle(argc, argv);
    cr_assert_eq(ret, 1);
}

Test(basic_tests, test_arguments_for_p1_bad_data_file)
{
    int argc = 2;
    char *argv[] = {"./navy", "tests/bad_data.txt", NULL};
    int ret = -1;

    ret = error_handle(argc, argv);
    cr_assert_eq(ret, 1);
}

Test(basic_tests, test_arguments_for_p1_bad_in_data_file)
{
    int argc = 2;
    char *argv[] = {"./navy", "tests/bad_lenght.txt", NULL};
    int ret = -1;

    ret = error_handle(argc, argv);
    cr_assert_eq(ret, 1);
}
