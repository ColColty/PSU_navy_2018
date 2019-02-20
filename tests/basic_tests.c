/*
** EPITECH PROJECT, 2018
** test.c
** File description:
** Tom
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>


void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

TestSuite(
    basic_tests,
    .init=redirect_all_std
);

Test(basic_tests, no_arguments)
{
}

Test(basic_tests, arguments_bad_type)
{
}

Test(basic_tests, arguments_good_and_bad_type)
{
}

Test(basic_tests, arguments_NULL)
{
}

Test(basic_tests, description)
{
}