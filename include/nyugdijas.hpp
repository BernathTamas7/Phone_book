#ifndef NYUGDIJAS_HPP
#define NYUGDIJAS_HPP

#include "szemely.hpp"

#include <iostream>
#include <string>

using namespace std;

class Nyugdijas: public Szemely{
    int Nyugdijazas;
    bool Klubtag;
public:
    Nyugdijas():Szemely(), Nyugdijazas(2000), Klubtag(false){}
    Nyugdijas(const Nev& nev, const Cim& cim, const Telefonszam& szam, int ny_ev, bool klub):Szemely(nev,szam,cim),Nyugdijazas(ny_ev),Klubtag(klub){}

    int getNyugdijazas() const;
    bool getKlubtag() const;

    void setNyugdijazas(int tmp);
    void setKlubtag(bool tmp);

    void kiir(ostream& os) const;
    void beolvas(istream& is);

    friend ostream& operator<<(ostream& os, const Nyugdijas& tmp);
    friend istream& operator>>(istream& is, Nyugdijas& tmp);

    void fajlba_ir(std::ostream& os);
};

#endif
