#ifndef DIAK_HPP
#define DIAK_HPP

#include "szemely.hpp"

#include <iostream>
#include <string>

using namespace std;

class Diak: public Szemely{
    string Iskola;
    int Evfolyam;
public:
    Diak():Szemely(), Iskola(""), Evfolyam(1){}
    Diak(const Nev& nev, const Cim& cim, const Telefonszam& szam, const string& isk, int evf):Szemely(nev,szam,cim),Iskola(isk),Evfolyam(evf){}

    string getIskola() const;
    int getEvfolyam() const;

    void setIskola(const string& tmp);
    void setEvfolyam(int tmp);

    void kiir(ostream& os) const;
    void beolvas(istream& is);

    friend ostream& operator<<(ostream& os, const Diak& tmp);
    friend istream& operator>>(istream& is, Diak& tmp);

    void fajlba_ir(std::ostream& os);
};

#endif
