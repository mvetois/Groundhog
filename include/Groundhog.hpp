/*
** EPITECH PROJECT, 2020
** Groundhog
** File description:
** Groundhog
*/

#ifndef GROUNDHOG_HPP_
#define GROUNDHOG_HPP_

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <iomanip>
#include <ios>
#include <bits/stdc++.h>

class Groundhog {
    public:
        Groundhog();
        ~Groundhog();
        void Core(size_t nb);
        void exec(size_t nb);
        void gCalcul(size_t nb);
        void rCalcul(size_t nb);
        void sCalcul(size_t nb);
        float aCalcul(size_t nb);
        void aberrations(size_t nb);

        std::vector<float> _data;
    private:
        std::string _input;
        size_t _count;
        float _g;
        float _r;
        float _rsave;
        float _s;
        std::vector<float> _avg;
        std::vector<float> _cpytmp;
};

int groundhog(int argc, char **argv);


#endif /* !GROUNDHOG_HPP_ */
