/*
** EPITECH PROJECT, 2020
** error handling
** File description:
** error
*/

#include <criterion/criterion.h>
#include "../include/Groundhog.hpp"

Test(error_01, error) {
    std::string bin = "./groundhog";
    char *input[] = {(char *)bin.c_str() , NULL};

    cr_assert_eq(groundhog(1, input), 84);
}

Test(error_02, error) {
    std::string bin = "./groundhog";
    std::string arg = "a";
    char *input[] = {(char *)bin.c_str() , (char *)arg.c_str(), NULL};

    cr_assert_eq(groundhog(2, input), 84);
}

Test(error_03, error) {
    std::string bin = "./groundhog";
    std::string arg = "-h";
    char *input[] = {(char *)bin.c_str() , (char *)arg.c_str(), NULL};

    cr_assert_eq(groundhog(2, input), 0);
}

Test(error_04, error) {
    std::string bin = "./groundhog";
    std::string arg = "0";
    char *input[] = {(char *)bin.c_str() , (char *)arg.c_str(), NULL};

    cr_assert_eq(groundhog(2, input), 84);
}