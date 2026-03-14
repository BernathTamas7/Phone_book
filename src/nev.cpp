#include "nev.hpp"
#include <iostream>
#include <string>

using namespace std;

///setter-getter fuggvenyek
string Nev::getVezetek() const {
    return Vezeteknev;
}

string Nev::getKereszt() const {
    return Keresztnev;
}

string Nev::getBece() const {
    return Becenev;
}

void Nev::setVezetek(string tmp) {
    Vezeteknev = tmp;
}

void Nev::setKereszt(string tmp) {
    Keresztnev = tmp;
}

void Nev::setBece(string tmp) {
    Becenev = tmp;
}
///-------------------------

//operator tulterheles, kesobbiekben a kereses fuggvenyekben segit
bool Nev::operator==(const Nev& n) const{
        return (Vezeteknev == n.Vezeteknev && Keresztnev == n.Keresztnev && Becenev == n.Becenev);
}

//a szep kiirasert felel
void Nev::kiir(ostream& os) const {
    cout << "Teljes nev: " << Vezeteknev << " " << Keresztnev << " (Becenev: " << Becenev << ")" << endl;
}

void Nev::beolvas(std::istream& is) {
    is >> Vezeteknev >> Keresztnev >> Becenev;
}

ostream& operator<<(ostream& os, const Nev& nev) {
    os << nev.Vezeteknev << " " << nev.Keresztnev << " (Becenev: " << nev.Becenev << ")";
    return os;
}
