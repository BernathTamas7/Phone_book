#include "szemely.hpp"
#include "uzleti.hpp"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//getter fuggveny
Cim Uzleti::getMunkahelyiCim() const {
    return munkahelyi;
}

//setter fuggveny
void Uzleti::setMunkahelyiCim(int irszam, const string& varos, const string& utca, int hazszam) {
    munkahelyi.setIrszam(irszam);
    munkahelyi.setVaros(varos);
    munkahelyi.setUtca(utca);
    munkahelyi.setHazszam(hazszam);
}

//beolvassa akarhonnan az adatot, minden elemet enterekkel elvalasztva kell megadni
void Uzleti::beolvas(std::istream& is) {
    std::string vezetek, kereszt, bece;
    int irszam, hazszam;
    std::string varos, utca;
    std::string privatszam, munkaszam;
    int mirszam, mhazszam;
    std::string mvaros, mutca;

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

    std::cout<<"Munkahelyi iranyitoszam: ";
    std::getline(is >> std::ws, sor);
    std::istringstream(sor) >> mirszam;
    std::cout<<"Munkahelyi varos: ";
    std::getline(is >> std::ws, mvaros);
    std::cout<<"Munkahelyi utca: ";
    std::getline(is >> std::ws, mutca);
    std::cout<<"Munkahelyi hazszam: ";
    std::getline(is >> std::ws, sor);
    std::istringstream(sor) >> mhazszam;
    setMunkahelyiCim(mirszam, mvaros, mutca, mhazszam);
    //system("cls");
}

//a konzolra torteno szep kiirasert felel, override-ol egy virtual fuggvenyt
void Uzleti::kiir(ostream& os) const {
    os << "Nev: " << name << endl;
    os << "Otthoni cim: " << otthoni << endl;
    os << "Telefonszam: " << number << endl;
    os << "Munkahelyi cim: " << munkahelyi << endl;
}

ostream& operator<<(ostream& os, const Uzleti& tmp) {
    tmp.kiir(os);
    return os;
}

istream& operator>>(istream& is, Uzleti& tmp) {
    tmp.beolvas(is);
    return is;
}

//fajlbairasert felelos fuggveny
void Uzleti::fajlba_ir(std::ostream& os){
    os<<name.getVezetek()<<std::endl;
    os<<name.getKereszt()<<std::endl;
    os<<name.getBece()<<std::endl;
    os<<otthoni.GetIrszam()<<std::endl;
    os<<otthoni.GetVaros()<<std::endl;
    os<<otthoni.GetUtca()<<std::endl;
    os<<otthoni.GetHazszam()<<std::endl;
    os<<number.getMunk()<<std::endl;
    os<<number.getOtth()<<std::endl;
    os<<munkahelyi.GetIrszam()<<std::endl;
    os<<munkahelyi.GetVaros()<<std::endl;
    os<<munkahelyi.GetUtca()<<std::endl;
    os<<munkahelyi.GetHazszam()<<std::endl;
}
