/*
** EPITECH PROJECT, 2020
** Groundhog
** File description:
** main
*/

#include "../include/Groundhog.hpp"

Groundhog::Groundhog()
{
    _count = 0;
    _g = 0;
    _r = 0;
    _s = 0;
    _moy = 0;
}

Groundhog::~Groundhog()
{}

void Groundhog::gCalcul(size_t nb)
{
    if (_data.size() <= nb)
        return;
    _g = 0;
    for (size_t c = _data.size() - nb; c != _data.size(); c++) {
        float temp = _data[c] - _data[c - 1];
        if (temp > 0)
            _g += temp;
    }
    _g = _g / nb;
}

void Groundhog::rCalcul(size_t nb)
{
    float one = 0;
    float two = 0;

    _rsave = _r; //savoir si on passe du positif au négatif ou inversement pour print "a switch occurs" à la fin de la ligne
    if (_data.size() <= nb)
        return;
    one = _data[_data.size() - 1 - nb];
    two = _data[_data.size() - 1];
    _r = round((two - one) / one * 100);
}

void Groundhog::sCalcul(size_t nb)
{
    float one = 0;
    float two = 0;

    _s = 0;
    if (_data.size() < nb)
        return;
    for (size_t a = _data.size() - nb; a !=  _data.size(); a++) {
        one += _data[a];
        two += (_data[a] * _data[a]);
    }
    _s = sqrt((two/nb)-(one/nb)*(one/nb)); //formule ecart type : sqrt(Variance) - Variance = (Somme de touts les nombres au carees)/Nombre de valeurs - Moyenne * Moyenne
}

float Groundhog::aCalcul(size_t nb)
{
    float sum = 0;

    if (_data.size() < nb)
        return (-1);
    for (int c = _data.size() - nb; c != _data.size(); c++)
        sum += _data[c];
    return (sum / nb);
}

void Groundhog::aberrations(size_t nb)
{
    //marche PASSSS !!! ça m'éverve
    size_t c = 0;
    for (c = 0; c != _data.size(); c++)
        _moy += _data[c];
    _moy = _moy / c;

    for (c = 0; c != _avg.size(); c++) {
        _avg[c] = (_avg[c] - 0.5);
        if (_avg[c] < 0)
            _avg[c] *= -1;
        std::cout << "  -  " << _avg[c] << std::endl;
    }
    _absData = _avg;
    sort(_absData.begin(), _absData.end());
    //for (c = 4; c != -1; c--) {
    for (c = _absData.size() - 5; c != _absData.size(); c++) {
        for (size_t a = 0; a != _avg.size(); a++) {
            if (_avg[a] == _absData[c])
                std::cout << "- "<<_data[a + nb - 1]  << "   " << _avg[a] << " " << _absData[c] << std::endl;
        }
    }



    // for (c = 0; c != _data.size(); c++)
    //     _absData.push_back(fabs(_moy - _data[c]));

    // std::sort(_absData.begin(), _absData.end());

    // for (c = 0; c !=  _data.size() - 1; c++)
    //     std::cout << _absData[c] << std::endl;

    // std::cout << "----------" << _moy << "----------" <<std::endl;
    // std::cout << std::setprecision(1) << std::fixed;
    // for (c = _absData.size() - 5; c != _absData.size(); c++) {
    //     for (size_t a = 0; a != _data.size(); a++) {
    //         if (fabs(_moy - _data[a]) == _absData[c])
    //             std::cout << "-- " << _data[a] << std::endl;
    //     }
    //     std::cout << _absData[c] << std::endl;
    // }
}

void Groundhog::exec(size_t nb)
{
    gCalcul(nb);
    rCalcul(nb);
    sCalcul(nb);
    std::cout << std::setprecision(2) << std::fixed; //précision des float à 2 apres la virgule
    if (_data.size() <= nb)
        std::cout << "g=nan\tr=nan%";
    else
        std::cout << "g=" << _g << "\tr=" << (int)_r << "%";
    if (_data.size() < nb)
        std::cout << "\ts=nan";
    else
        std::cout << "\ts=" << _s;
    if (_rsave && ((_rsave < 0 && _r >= 0) || (_rsave >= 0 && _r < 0))) {
        std::cout << "\ta switch occurs";
        _count++;
    }
    std::cout << std::endl;
    float bb = aCalcul(nb) - 2 * _s;
    float bh = aCalcul(nb) + 2 * _s;
    //std::cout << "-- " << bb << " " << bh << std::endl;
    if (bb != -1 && bh != -1)
        _avg.push_back((atof(_input.c_str()) - bb) / (bh - bb));
}

void Groundhog::Core(size_t nb)
{
    while (1) {
        std::scanf("%s", _input.c_str());
        if (std::strcmp(_input.c_str(), "STOP") == 0)
            break;
        else if (std::atof(_input.c_str()) != 0) {
            _data.push_back(std::atof(_input.c_str()));
            exec(nb);
        }
    }
    std::cout << "Global tendency switched " << _count << " times" << std::endl;
    aberrations(nb);
}

int print_help(int return_value, std::string bin)
{
    std::cout << "SYNOPSIS\n\t"<< bin << " period\nDESCRIPTION\n\tperiod\tthe number of days defining a period" << std::endl;
    return (return_value);
}

int groundhog(int argc, char **argv)
{
    Groundhog g;
    if (argc != 2)
        return (print_help(84 , argv[0]));
    if (!std::strcmp("-h", argv[1]))
        return (print_help(0, argv[0]));
    if (std::atoi(argv[1]) < 1)
        return (print_help(84 , argv[0]));
    g.Core((size_t)atoi(argv[1]));
    return (0);
}