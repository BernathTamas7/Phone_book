#ifndef FAJLKEZELES_HPP
#define FAJLKEZELES_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "telefonkonyv.hpp"

class Fajlkezeles{
    std::string fajlnev = "adatok.txt";
    void setFajlnev(const std::string tmp){
        fajlnev = tmp;
    }
public:
    Fajlkezeles(){}

    void Fajlbairas(Telefonkonyv& konyv);

    void Fejlbeolvasas(Telefonkonyv& konyv);
    ~Fajlkezeles(){}
};

#endif // FAJLKEZELES_HPP
