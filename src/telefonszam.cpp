#include "telefonszam.hpp"

#include <iostream>
#include <string>

using namespace std;

///setter-getter fuggvenyek
string Telefonszam::getMunk() const{
    return Munkahelyi;
}

string Telefonszam::getOtth() const{
    return Otthoni;
}

void Telefonszam::setMunk(string tmp){
    Munkahelyi = tmp;
}

void Telefonszam::setOtth(string tmp){
    Otthoni = tmp;
}
///----------------------------------

void Telefonszam::kiir() const{
    cout << "Munkahelyi szam: " << Munkahelyi << ", Otthoni szam: " << Otthoni << endl;
}

bool Telefonszam::operator==(const Telefonszam& masik) const{
    return (Munkahelyi == masik.Munkahelyi && Otthoni == masik.Otthoni);
}

ostream& operator<<(ostream& os, const Telefonszam& telefonszam) {
    os << "Munkahelyi: " << telefonszam.Munkahelyi << ", Otthoni: " << telefonszam.Otthoni;
    return os;
}
