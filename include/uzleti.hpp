#ifndef UZLETI_HPP
#define UZLETI_HPP

#include "szemely.hpp"

#include <iostream>
#include <string>

using namespace std;

class Uzleti: public Szemely{
    Cim munkahelyi;
public:
    Uzleti(): Szemely(), munkahelyi(){}
    Uzleti(const Nev& nev, const Cim& cim, const Telefonszam& szam, const Cim& munka): Szemely(nev,szam,cim), munkahelyi(munka){}

    Cim getMunkahelyiCim() const;
    void setMunkahelyiCim(int irszam, const string& varos, const string& utca, int hazszam);

    void kiir(ostream& os) const;
    void beolvas(istream& is);

    friend ostream& operator<<(ostream& os, const Uzleti& tmp);
    friend istream& operator>>(istream& is, Uzleti& tmp);

    void fajlba_ir(std::ostream& os);
};

#endif
