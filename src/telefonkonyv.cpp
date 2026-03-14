#include "telefonkonyv.hpp"

#include <iostream>
#include <string>

//felvesz egy szemely pointert a telefonkonyvbe
void Telefonkonyv::Felvesz(Szemely* s){
    Tarolo.Felvesz(s);
}


//beker egy indexet es kitorli azt az elemet a telefonkonyvbol
void Telefonkonyv::Torol_index(){
    std::cout<<"Adj meg egy indexet: "<<std::endl;
    int i;
    std::cin>>i;
    //system("cls");
    if(i < this->getMeret()){
        Tarolo.Torol(i);

    }
    else{
        std::cout<<"Tul nagy index, nem tortent torles"<<std::endl;
    }
}

//nevet ker be es ez alapjan torli az elemet a telefonkonyvbol
void Telefonkonyv::Torol_nev(){
    int valid = 0;
    std::cout<<"(Vezeteknev Keresztnev Becenev) formatumban"<<std::endl;
    Nev n;
    n.beolvas(std::cin);
    for(int i = 0; i < Tarolo.getMeret(); i++){
        Szemely* seged = Tarolo.getElements()[i];
        if(seged->getNev() == n){
            Tarolo.Torol(i);
            i--;
            valid++;
        }
    }
    //system("cls");
    if(valid == 0){
        std::cout<<"Nincs ilyen nevu kontakt, nem tortent torles"<<std::endl;
    }

}

//kilistaz minden elemet a telefonkonyvbol tetszoleges kimenetre
void Telefonkonyv::ListazOsszes(std::ostream& os) const{
    for(int i = 0; i < Tarolo.getMeret(); i++){
        os << *Tarolo.getElements()[i] << std::endl;
    }
}

//beker egy nevet es ha van ilyen nevu szemely kiirja konzolra az adatait, ha nincs azt is kozli a felhasznaloval
void Telefonkonyv::KeresNev() const{
    std::cout<<"Adjon meg egy nevet (Vezeteknev Keresztnev Becenev) formatumban"<<std::endl;
    std::string vez;
    std::string ker;
    std::string bec;

    std::cin>>vez>>ker>>bec;
    Nev n(vez, ker, bec);

    bool van = false;
    for(int i = 0; i < Tarolo.getMeret(); i++){
        Szemely * seged = Tarolo.getElements()[i];
        if(seged->getNev() == n){
            std::cout <<"Van talalat,("<<i<< ". index) "<< *seged<<std::endl;
            van = true;
        }
    }
    if(!van){
        std::cout<<"Nincs ilyen nevu szemely"<<std::endl;
    }
}

//telefonszam alapjan lehet keresni kontaktokat, ha talal egyezest kiirja az adatokat konzolra ha nem kiirja hogy nem talalt
void Telefonkonyv::KeresSzam() const{
    std::cout << "Adjon meg egy munkahelyi es otthoni szamot (szokozzel elvalasztva): ";
    std::string munkaszam, privatszam;
    std::cin >> munkaszam >> privatszam;

    Telefonszam sz(munkaszam, privatszam);

    bool van = false;
    for(int i = 0; i < Tarolo.getMeret(); i++){
        Szemely * seged = Tarolo.getElements()[i];
        if(seged->getTelefon() == sz){
            std::cout <<"Van talalat,("<<i<< ". index) "<< *seged<<std::endl;
            van = true;
        }
    }
    if(!van){
        std::cout<<"Nincs ilyen szamu szemely"<<std::endl;
    }
}

void Telefonkonyv::Rendez(const std::string& szempont) {
    int n = Tarolo.getMeret();
    Szemely** tomb = Tarolo.getElements();

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            bool csere = false;

            if (szempont == "vezeteknev") {
                if (tomb[i]->getNev().getVezetek() > tomb[j]->getNev().getVezetek()) {
                    csere = true;
                }
            } else if (szempont == "varos") {
                if (tomb[i]->getCim().GetVaros() > tomb[j]->getCim().GetVaros()) {
                    csere = true;
                }
            } else if (szempont == "becenev") {
                if (tomb[i]->getNev().getBece() > tomb[j]->getNev().getBece()) {
                    csere = true;
                }
            }
            else {
                std::cout<< "Ismeretlen rendezesi szempont: " << szempont << std::endl;
            }

            if (csere) {
                Szemely* temp = tomb[i];
                tomb[i] = tomb[j];
                tomb[j] = temp;
            }
        }
    }
}

//Szurest hajt vegre altalunk megadott szempontok alapjan
void Telefonkonyv::SzuresAlapjan(const std::string& mi, std::ostream& os) const {
    std::string ertek = "";
    std::cout<<"Adja meg az erteket:"<<std::endl;
    int seged = 0;

    std::cin>>ertek;
    for (int i = 0; i < Tarolo.getMeret(); ++i) {
        Szemely* s = Tarolo.getElements()[i];

        if (mi == "varos" && s->getCim().GetVaros() == ertek) {
            os << *s << std::endl;
            seged++;

        } else if (mi == "vezeteknev" && s->getNev().getVezetek() == ertek) {
            os << *s << std::endl;
            seged++;

        } else if (mi == "becenev" && s->getNev().getBece() == ertek) {
            os << *s << std::endl;
            seged++;
        }
    }
    if(seged == 0){
        std::cout<<"Nincs ilyen kontakt"<<std::endl;
    }
}

//Alap tipusu elemet vesz fel a Telefonkonyvbe
void Telefonkonyv::AlapFelvesz(){
    Alap* d = new Alap;
    d->beolvas(std::cin);
    Felvesz(d);
}

//Diak tipusu elemet vesz fel a Telefonkonyvbe
void Telefonkonyv::DiakFelvesz(){
    Diak* d = new Diak;
    d->beolvas(std::cin);
    Felvesz(d);
}

//Uzleti tipusu elemet vesz fel a Telefonkonyvbe
void Telefonkonyv::UzletiFelvesz(){
    Uzleti* d = new Uzleti;
    d->beolvas(std::cin);
    Felvesz(d);
}

//Nyugdijas tipusu elemet vesz fel a Telefonkonyvbe
void Telefonkonyv::NyugdijasFelvesz(){
    Nyugdijas* d = new Nyugdijas;
    d->beolvas(std::cin);
    Felvesz(d);
}

//menukezelokent mukodik, a modositasokert felel
void Telefonkonyv::Modosit() {
    std::cout << "Adjon meg egy indexet: ";
    int index = 0;
    std::cin >> index;

    if (index < 0 || index >= Tarolo.getMeret()) {
        std::cout << "Érvénytelen" << std::endl;
        return;
    }

    std::cout << "Adjon meg egy szamot amire modositani szeretne (Alap: 1, Uzleti: 2, Diak: 3, Nyugdijas: 4): "<<std::endl;
    int tipus;
    std::cin >> tipus;

    Szemely* uj = nullptr;

    switch (tipus) {
        case 1:
            uj = new Alap;
            uj->beolvas(std::cin);
            break;
        case 2:
            uj = new Uzleti;
            uj->beolvas(std::cin);
            break;
        case 3:
            uj = new Diak;
            uj->beolvas(std::cin);
            break;
        case 4:
            uj = new Nyugdijas;
            uj->beolvas(std::cin);
            break;
    }

    Tarolo.Modosit(index, uj);
}

//getter fuggveny
int Telefonkonyv::getMeret() const{
    return Tarolo.getMeret();
}


