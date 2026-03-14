#ifndef NEV_HPP
#define NEV_HPP

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Nev{
    string Vezeteknev;
    string Keresztnev;
    string Becenev;
public:
    Nev():Vezeteknev(""), Keresztnev(""), Becenev(""){}
    Nev(const string& vezetek, const string& kereszt, const string& bece): Vezeteknev(vezetek), Keresztnev(kereszt), Becenev(bece){}

    string getVezetek() const;
    string getKereszt() const;
    string getBece() const;

    void setVezetek(string tmp);
    void setKereszt(string tmp);
    void setBece(string tmp);

    void beolvas(std::istream& is);
    bool operator==(const Nev& n) const;
    void kiir(ostream& os) const;
    friend ostream& operator<<(ostream& os, const Nev& nev);
};

#endif
