#include <iostream>
#include <string>

#include "rendez_menu.hpp"

//menukezelo fuggveny, a rendezes tipsat lehet kivalasztani
void rendez_menu(Telefonkonyv& konyv, std::istream& is, std::ostream& os){
    int r_valasztas = 0;
    int seged = 0;
    do{
        os <<"*****RENDEZES MENU *****"<<std::endl;
        os <<"Vezeteknev: 1"<<std::endl;
        os <<"Becenev: 2"<<std::endl;
        os <<"Varos: 3"<<std::endl;
        os <<"Kilepes a fomenube: 4"<<std::endl;

        is >>r_valasztas;
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

        switch(r_valasztas){
        case 1:
            //system("cls");
            konyv.Rendez("vezeteknev");
            break;
        case 2:
            //system("cls");
            konyv.Rendez("becenev");
            break;
        case 3:
            //system("cls");
            konyv.Rendez("varos");
            break;
        case 4:
            //system("cls");
            break;
        default:
            std::cout<<"Nincsen ilyen menupont"<<std::endl;
            break;
        }
    }while(r_valasztas != 4);
}
