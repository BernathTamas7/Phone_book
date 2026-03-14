#ifndef SZEMELY_HPP
#define SZEMELY_HPP

#include "cim.hpp"
#include "telefonszam.hpp"
#include "nev.hpp"

#include <iostream>
#include <string>

using namespace std;

class Szemely{
protected:

    Nev name;
    Telefonszam number;
    Cim otthoni;
public:
    Szemely(): name(), number(), otthoni(){}
    Szemely(const Nev& n, const Telefonszam& sz, const Cim& c): name(n), number(sz), otthoni(c){}

    Nev getNev() const;
    Telefonszam getTelefon() const;
    Cim getCim() const;

    void setNev(const string& vezetek, const string& kereszt, const string& bece);
    void setTelefon(const string& munkahelyi, const string& privat);
    void setCim(int irszam, const string& varos, const string& utca, int hazszam);

    virtual void kiir(ostream& os) const = 0;

    friend ostream& operator<<(ostream& os, const Szemely& szemely) {
        szemely.kiir(os);
        return os;
    }
    virtual void beolvas(std::istream& is) = 0;

    virtual void fajlba_ir(std::ostream& os) = 0;

    virtual ~Szemely(){}
};

#endif
