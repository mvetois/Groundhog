/*
** EPITECH PROJECT, 2020
** error handling
** File description:
** error
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/Groundhog.hpp"

void redirect_all_stdout(void)
{
        cr_redirect_stdout();
        cr_redirect_stderr();
}

Test(functions_01, error) {
    Groundhog g;
    g.exec(1);
}

// Test(functions_02, error, .init=redirect_all_stdout) {
//     Groundhog g;
//     g._data.push_back(1);
//     g._data.push_back(2);
//     g._data.push_back(3);
//     g._data.push_back(4);
//     g._data.push_back(2);
//     g._data.push_back(3);
//     g.exec(2);
//     cr_assert_stdout_eq_str("g=0.50\tr=-25%\ts=0.50\ta switch occurs\n", "");
// }

Test(functions_03, error, .init=redirect_all_stdout) {
    Groundhog g;
    g._data.push_back(1);
    g.exec(2);
    g._data.push_back(2);
    g.exec(2);
    g._data.push_back(3);
    g.exec(2);
    g._data.push_back(4);
    g.exec(2);
    g._data.push_back(2);
    g.exec(2);
    g._data.push_back(3);
    g.exec(2);
    g.aberrations(2);
    //cr_assert_stdout_eq_str("5 weirdest values are [2.0, 2.0, 2.0, 2.0, 2.0]\n", "");
}