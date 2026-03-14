#include "kereses.hpp"

#include <iostream>
#include <string>


//menukezelo fuggveny, milyen alapon keresunk
void keres_menu(Telefonkonyv& konyv, std::istream& is, std::ostream& os){
    int valasztas = 0;
    int seged=  0;
    do{
        os <<"*****KERESES MENU*****"<<std::endl;
        os <<"Nev szerint: 1"<<std::endl;
        os <<"Szam szerint: 2"<<std::endl;
        os <<"Kilepes: 3"<<std::endl;


        is >>valasztas;
        if (is.fail()) {
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            os << "Ervenytelen bemenet, szamot irj be!" << std::endl;
            seged++;
            if (seged >= 5) {
                os << "Tul sok hiba, kilepek a menubol." << std::endl;
                break;
            }
            continue;
        }

        switch(valasztas){
        case 1:
            //system("cls");
            konyv.KeresNev();
            break;
        case 2:
            //system("cls");
            konyv.KeresSzam();
            break;
        case 3:
            //system("cls");
            break;
        default:
            std::cout<<"Nincsen ilyen menupont"<<std::endl;
            break;
        }

    }while(valasztas != 3);
}
