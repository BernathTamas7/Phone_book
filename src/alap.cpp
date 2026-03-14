#include "alap.hpp"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//visszaadja az objektum markajat
string Alap::getMarka() const {
    return marka;
}

//beallitja a markat
void Alap::setMarka(const string& tmp) {
    marka = tmp;
}

//a konzolra torteno szep kiirasert felel, override-ol egy virtual fuggvenyt
void Alap::kiir(ostream& os) const {
    os << "Nev: " << name << endl;
    os << "Otthoni cim: " << otthoni << endl;
    os << "Telefonszam: " << number << endl;
    os << "Marka: " << marka << endl;
}



//beolvassa akarhonnan az adatot, minden elemet enterekkel elvalasztva kell megadni
void Alap::beolvas(std::istream& is) {
    std::string vezetek, kereszt, bece;
    int irszam, hazszam;
    std::string varos, utca;
    std::string munkaszam, privatszam;
    std::string m;


   std::cout<<"Vezeteknev: ";
    std::getline(is >> std::ws, vezetek);
    std::cout<<"Keresztnev: ";
    std::getline(is >> std::ws, kereszt);
    std::cout<<"Becenev: ";
    std::getline(is >> std::ws, bece);
    setNev(vezetek, kereszt, bece);

    std::string sor;
    std::cout<<"Iranyitoszam: ";
    std::getline(is >> std::ws, sor);
    std::istringstream(sor) >> irszam;
    std::cout<<"Varos: ";
    std::getline(is >> std::ws, varos);
    std::cout<<"Utca: ";
    std::getline(is >> std::ws, utca);
    std::cout<<"Hazszam: ";
    std::getline(is >> std::ws, sor);
    std::istringstream(sor) >> hazszam;
    setCim(irszam, varos, utca, hazszam);

    std::cout<<"Munkahelyi szam: ";
    std::getline(is >> std::ws, munkaszam);
    std::cout<<"Privat szam: ";
    std::getline(is >> std::ws, privatszam);
    setTelefon(munkaszam, privatszam);

    std::cout<<"Marka: ";
    std::getline(is >> std::ws, m);
    setMarka(m);
    //system("cls");
}


//operatot tulterheles
ostream& operator<<(ostream& os, const Alap& tmp) {
    tmp.kiir(os);
    return os;
}

istream& operator>>(istream& is, Alap& tmp) {
    tmp.beolvas(is);
    return is;
}

//fajlba irasert felelo kiiro fuggveny
void Alap::fajlba_ir(std::ostream& os){
    os<<name.getVezetek()<<std::endl;
    os<<name.getKereszt()<<std::endl;
    os<<name.getBece()<<std::endl;
    os<<otthoni.GetIrszam()<<std::endl;
    os<<otthoni.GetVaros()<<std::endl;
    os<<otthoni.GetUtca()<<std::endl;
    os<<otthoni.GetHazszam()<<std::endl;
    os<<number.getMunk()<<std::endl;
    os<<number.getOtth()<<std::endl;
    os<<marka<<std::endl;
}




