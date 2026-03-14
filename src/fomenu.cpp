#include <iostream>
#include <string>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "fomenu.hpp"
#include "kezeles_menu.hpp"
#include "felvevo.hpp"
#include "szures.hpp"
#include "kereses.hpp"


//Ez a fuggveny a fomenu kezeleseert felel, szamokat ker be futasa soran amiket a felhasznalo ad meg,
//ez alapjan haladhat a menuben

void fomenu(Telefonkonyv& konyv, std::istream& is, std::ostream& os, Fajlkezeles& fajl){
    int valasztas = 0;
    int seged = 0;
    do{
        os <<"***** MENU *****"<<std::endl;
        os <<"Listazas: 1"<<std::endl;
        os <<"Rendezes: 2"<<std::endl;
        os <<"Kezeles: 3"<<std::endl;
        os <<"Szures: 4"<<std::endl;
        os <<"Kereses: 5"<<std::endl;
        os <<"Fajlkezeles: 6"<<std::endl;
        os <<"Kilepes a programbol: 7"<<std::endl;



        is >>valasztas;

        if (is.fail()) {
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            os << "Ervenytelen bemenet, szamot irj be!\n";
            seged++;
            if(seged > 5){
                std::cout<<"Tul sok hiba, kilepek a programbol!"<<std::endl;
                break;
            }
            continue;
        }

        switch(valasztas){
        case 1:
            //system("cls");
            //kilistazza a konzolra az osszes kontaktot
            konyv.ListazOsszes(std::cout);
            break;
        case 2:
            //system("cls");
            //meghivja a rendez menut
            rendez_menu(konyv, std::cin, std::cout);
            break;
        case 3:
            //system("cls");
            //meghivja a kezeles menut
            kezeles_menu(konyv,std::cin, std::cout);
            break;
        case 4:
            //system("cls");
            //meghivja a szures menut
            SzuresMenu(konyv, std::cin, std::cout);
            break;
        case 5:
            //system("cls");
            //meghivja a kereses menut
            keres_menu(konyv,std::cin, std::cout);
            break;

        case 6:
            //system("cls");
            //meghivja a fajlkezeles menut
            fajlkezeles_menu(konyv, fajl);
            break;
        case 7:
            //system("cls");
            break;
        default:
            //system("cls");
            std::cout<<"Nincsen ilyen menupont"<<std::endl;
            break;
        }


    }while(valasztas != 7);
}



