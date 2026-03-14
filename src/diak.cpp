#include "diak.hpp"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

///getter-setter fuggvenyek

string Diak::getIskola() const{
    return Iskola;
}

int Diak::getEvfolyam() const{
    return Evfolyam;
}

void Diak::setEvfolyam(int tmp){
    Evfolyam = tmp;
}

void Diak::setIskola(const string& tmp){
    Iskola = tmp;
}

///*******************************

//a konzolra torteno szep kiirasert felel, override-ol egy virtual fuggvenyt
void Diak::kiir(ostream& os) const {
    os << "Nev: " << name << endl;
    os << "Otthoni cim: " << otthoni << endl;
    os << "Telefonszam: " << number << endl;
    os << "Iskola: " << Iskola << endl;
    os << "Evfolyam: " << Evfolyam << endl;
}

//beolvassa akarhonnan az adatot, minden elemet enterekkel elvalasztva kell megadni
void Diak::beolvas(std::istream& is) {
    std::string vezetek, kereszt, bece;
    int irszam, hazszam;
    std::string varos, utca;
    std::string munkaszam, privatszam;
    std::string isk;
    int evf;

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

    std::cout<<"Iskola: ";
    std::getline(is >> std::ws, isk);
    std::cout<<"Evfolyam: ";
    std::getline(is >> std::ws, sor);
    std::istringstream(sor) >> evf;
    setEvfolyam(evf);
    setIskola(isk);
    //system("cls");
}

ostream& operator<<(ostream& os, const Diak& tmp) {
    tmp.kiir(os);
    return os;
}

istream& operator>>(istream& is, Diak& tmp) {
    tmp.beolvas(is);
    return is;
}

//fajlba irasert felelo kiiro fuggveny
void Diak::fajlba_ir(std::ostream& os){
    os<<name.getVezetek()<<std::endl;
    os<<name.getKereszt()<<std::endl;
    os<<name.getBece()<<std::endl;
    os<<otthoni.GetIrszam()<<std::endl;
    os<<otthoni.GetVaros()<<std::endl;
    os<<otthoni.GetUtca()<<std::endl;
    os<<otthoni.GetHazszam()<<std::endl;
    os<<number.getMunk()<<std::endl;
    os<<number.getOtth()<<std::endl;
    os<<Iskola<<std::endl;
    os<<Evfolyam<<std::endl;
}
