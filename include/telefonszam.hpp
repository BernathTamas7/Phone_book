#ifndef TELEFONSZAM_HPP
#define TELEFONSZAM_HPP

#include <iostream>
#include <string>

using namespace std;

class Telefonszam{
    string Munkahelyi;
    string Otthoni;
public:
    Telefonszam():Munkahelyi("ures"), Otthoni("Ures"){}
    Telefonszam(const string& Munkahelyi, const string& Otthoni): Munkahelyi(Munkahelyi), Otthoni(Otthoni){}

    string getMunk() const;
    string getOtth() const;

    void setMunk(string tmp);
    void setOtth(string tmp);

    void kiir() const;

    friend ostream& operator<<(ostream& os, const Telefonszam& telefonszam);
    bool operator==(const Telefonszam& masik) const;
};

#endif
