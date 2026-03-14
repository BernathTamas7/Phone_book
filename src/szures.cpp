#include <iostream>
#include <string>
#include "szures.hpp"

void SzuresMenu(Telefonkonyv& konyv, std::istream& is, std::ostream& os){
    int sz_valasztas = 0;
    int seged = 0;
    do{
        os <<"Mi alapjan legyen a szures?"<<std::endl;
        os <<"Vezeteknev: 1"<<std::endl;
        os <<"Becenev: 2"<<std::endl;
        os <<"Varos: 3"<<std::endl;
        os <<"Kilepes a fomenube: 4"<<std::endl;

        is >>sz_valasztas;

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

        switch(sz_valasztas){
        case 1:
            //system("cls");
            konyv.SzuresAlapjan("vezeteknev",std::cout);
            break;
        case 2:
            //system("cls");
            konyv.SzuresAlapjan("becenev",std::cout);
            break;
        case 3:
            //system("cls");
            konyv.SzuresAlapjan("varos",std::cout);
            break;
        case 4:
            //system("cls");
            break;
        default:
            std::cout<<"Nincsen ilyen menupont"<<std::endl;
            break;
        }
    }while(sz_valasztas != 4);
}
