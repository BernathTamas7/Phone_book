#ifndef ALAP_HPP
#define ALAP_HPP

#include "szemely.hpp"

#include <iostream>
#include <string>

using namespace std;

class Alap: public Szemely{
    string marka;
public:
    Alap(): Szemely(), marka(""){}
    Alap(const Nev& nev, const Cim& cim, const Telefonszam& szam, const string& m): Szemely(nev,szam,cim), marka(m){}

    string getMarka() const;
    void setMarka(const string& tmp);

    void kiir(ostream& os) const;
    void beolvas(istream& is);

    friend ostream& operator<<(ostream& os, const Alap& tmp);
    friend istream& operator>>(istream& is, Alap& tmp);

    void fajlba_ir(std::ostream& os);
};

#endif
