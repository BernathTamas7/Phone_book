#include "telefonkonyv.hpp"
#include "fajlkezeles.hpp"
#include "felvevo.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

//menukezelo fuggvenykent funkcional
void fajlkezeles_menu(Telefonkonyv& konyv, Fajlkezeles& fajl){
    int k_valasztas = 0;
    int seged = 5;
    do{
        std::cout <<"*****FAJLKEZELES MENU *****"<<std::endl;
        std::cout <<"Fajlbairas: 1"<<std::endl;
        std::cout <<"Beolvasas: 2"<<std::endl;
        std::cout <<"Kilepes a fomenube: 3"<<std::endl;


        std::cin >> k_valasztas;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ervenytelen bemenet, szamot irj be!\n";
            seged++;
        if (seged > 5) {
            std::cout << "Tul sok hiba, kilepek a programbol!" << std::endl;
            break;
        }
        continue;
    }

        switch(k_valasztas){
        case 1:
            //system("cls");
            fajl.Fajlbairas(konyv);
            break;
        case 2:
            fajl.Fejlbeolvasas(konyv);
            //system("cls");
            break;
        case 3:
            //system("cls");
            break;
        default:
            std::cout<<"Nincsen ilyen menupont"<<std::endl;
            break;
        }
    }while(k_valasztas != 3);
}
