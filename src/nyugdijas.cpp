#include "nyugdijas.hpp"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

///setter-getter fuggvenyek
bool Nyugdijas::getKlubtag() const{
    return Klubtag;
}

int Nyugdijas::getNyugdijazas() const{
    return Nyugdijazas;
}

void Nyugdijas::setNyugdijazas(int tmp){
    Nyugdijazas = tmp;
}

void Nyugdijas::setKlubtag(bool tmp){
    Klubtag = tmp;
}
///----------------------------


//a konzolra torteno szep kiirasert felel, override-ol egy virtual fuggvenyt
void Nyugdijas::kiir(ostream& os) const {
    os << "Nev: " << name << endl;
    os << "Otthoni cim: " << otthoni << endl;
    os << "Telefonszam: " << number << endl;
    os << "Nyugdijazas eve: " << Nyugdijazas << endl;
    os << "Klubtag: " << (Klubtag ? "igen" : "nem") << endl;
}

//beolvassa akarhonnan az adatot, minden elemet enterekkel elvalasztva kell megadni
void Nyugdijas::beolvas(std::istream& is) {
    std::string vezetek, kereszt, bece;
    int irszam, hazszam;
    std::string varos, utca;
    std::string munkaszam, privatszam;
    int ny_ev;
    std::string klubszoveg;

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

    std::cout<<"Nyugdijazas eve: ";
    std::getline(is >> std::ws, sor);
    std::istringstream(sor) >> ny_ev;
    setNyugdijazas(ny_ev);

    std::cout<<"Klubtag-e? (igen/nem): ";
    std::getline(is >> std::ws, klubszoveg);
    setKlubtag(klubszoveg == "igen");
    //system("cls");
}

ostream& operator<<(ostream& os, const Nyugdijas& tmp) {
    tmp.kiir(os);
    return os;
}

istream& operator>>(istream& is, Nyugdijas& tmp) {
    tmp.beolvas(is);
    return is;
}

//fajlba irasert felelo kiiro fuggveny
void Nyugdijas::fajlba_ir(std::ostream& os){
    os<<name.getVezetek()<<std::endl;
    os<<name.getKereszt()<<std::endl;
    os<<name.getBece()<<std::endl;
    os<<otthoni.GetIrszam()<<std::endl;
    os<<otthoni.GetVaros()<<std::endl;
    os<<otthoni.GetUtca()<<std::endl;
    os<<otthoni.GetHazszam()<<std::endl;
    os<<number.getMunk()<<std::endl;
    os<<number.getOtth()<<std::endl;
    os<<Nyugdijazas<<std::endl;
    if(Klubtag){
        os<<"igen"<<std::endl;
    }
    else{
        os<<"nem"<<std::endl;
    }
}
