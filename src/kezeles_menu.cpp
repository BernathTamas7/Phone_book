#include "telefonkonyv.hpp"
#include <iostream>
#include <string>

#include "felvevo.hpp"

//menukezelo fuggveny, milyen valtoztatasokat akarunk vegrehajtani
void kezeles_menu(Telefonkonyv& konyv, std::istream& is, std::ostream& os){
    int k_valasztas = 0;
    int seged = 5;
    do{
        os <<"*****KEZELES MENU *****"<<std::endl;
        os <<"Felvesz: 1"<<std::endl;
        os <<"Torol (index): 2"<<std::endl;
        os <<"Torol (Nev): 3"<<std::endl;
        os <<"Modosit: 4"<<std::endl;
        os <<"Kilepes: 5"<<std::endl;


        is >>k_valasztas;
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

        switch(k_valasztas){
        case 1:
            //system("cls");
            felvevo(konyv,std::cin, std::cout);
            break;
        case 2:
            //system("cls");
            konyv.Torol_index();
            break;
        case 3:
            //system("cls");
            konyv.Torol_nev();
            break;
        case 4:
            //system("cls");
            konyv.Modosit();
            break;
        case 5:
            //system("cls");
            break;
        default:
            std::cout<<"Nincsen ilyen menupont"<<std::endl;
            break;
        }
    }while(k_valasztas != 5);
}
