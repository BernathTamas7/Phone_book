
#include "szemely.hpp"

#include <iostream>
#include <string>

using namespace std;

///setter-getter fuggvenyek
Nev Szemely::getNev() const{
    return Nev(name.getVezetek(), name.getKereszt(), name.getBece());
}

Telefonszam Szemely::getTelefon() const{
    return Telefonszam(number.getMunk(), number.getOtth());
}

Cim Szemely::getCim() const{
    return Cim(otthoni.GetIrszam(), otthoni.GetVaros(), otthoni.GetUtca(), otthoni.GetHazszam());
}

void Szemely::setNev(const string& vezetek, const string& kereszt, const string& bece){
    name.setVezetek(vezetek);
    name.setKereszt(kereszt);
    name.setBece(bece);
}

void Szemely::setCim(int irszam, const string& varos, const string& utca, int hazszam){
    otthoni.setIrszam(irszam);
    otthoni.setVaros(varos);
    otthoni.setUtca(utca);
    otthoni.setHazszam(hazszam);
}

void Szemely::setTelefon(const string& munkahelyi, const string& privat){
    number.setMunk(munkahelyi);
    number.setOtth(privat);
}
///--------------------------
