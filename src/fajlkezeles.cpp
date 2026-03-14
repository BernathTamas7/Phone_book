#include "fajlkezeles.hpp"
#include "sajatvektor.hpp"
#include "telefonkonyv.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

//fajlbairasert felel, ha a fajl nem letezik akkor letrehoz egyet, ha mar letezik felulirja, ha nem sikerul neki hibauzenetet dob
void Fajlkezeles::Fajlbairas(Telefonkonyv& konyv){
    std::ofstream beiras(fajlnev);
    if(!beiras){
        std::cout<<"Nincs ilyen fajl: "<<fajlnev<<std::endl;
        return;
    }


    for(int i = 0; i < konyv.getMeret(); i++){
        Szemely* ptr = konyv.getTarolo().getElements()[i];
        if(dynamic_cast<Alap*>(ptr)){
            beiras<<"Alap"<<std::endl;
            ptr->fajlba_ir(beiras);
        }
        else if(dynamic_cast<Uzleti*>(ptr)){
            beiras<<"Uzleti"<<std::endl;
            ptr->fajlba_ir(beiras);
        }
        else if(dynamic_cast<Nyugdijas*>(ptr)){
            beiras<<"Nyugdijas"<<std::endl;
            ptr->fajlba_ir(beiras);
        }
        else if(dynamic_cast<Diak*>(ptr)){
            beiras<<"Diak"<<std::endl;
            ptr->fajlba_ir(beiras);
        }


    }
}

//fajlbeolvasasert felel ha nem talalja a fajlt hibauzenetet dob
void Fajlkezeles::Fejlbeolvasas(Telefonkonyv& konyv){
    std::ifstream beolvas(fajlnev);
    if(!beolvas){
        std::cout<<"Nem letezik a fajl"<<std::endl;
        return;
    }

    std::string sor;
    while(std::getline(beolvas,sor)){
        int valid = 0;

        Szemely* ujszemely;
        if("Alap" == sor){
            ujszemely = new Alap;
            valid++;
        }
        if("Uzleti" == sor){
            ujszemely = new Uzleti;
            valid++;
        }
        if("Nyugdijas" == sor){
            ujszemely = new Nyugdijas;
            valid++;
        }
        if("Diak" == sor){
            ujszemely = new Diak;
            valid++;
        }

        if(valid){
            ujszemely->beolvas(beolvas);
            konyv.Felvesz(ujszemely);
        }
        valid =  0;

    }
}
