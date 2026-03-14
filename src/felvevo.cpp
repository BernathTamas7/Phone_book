#include "felvevo.hpp"

#include <iostream>
#include <string>


//menukezelo fuggvenykent funkcional, eldonthetjuk hogy milyen tipusu kontaktot akarunk felvenni
void felvevo(Telefonkonyv& konyv, std::istream& is, std::ostream& os){
    int f_valasztas = 0;
    int seged = 0;
    do{
        os <<"Milyen tipust szeretne felvenni?"<<std::endl;
        os <<"Alap: 1"<<std::endl;
        os <<"Uzleti: 2"<<std::endl;
        os <<"Diak: 3"<<std::endl;
        os <<"Nyugdijas: 4"<<std::endl;
        os <<"Kilepes a kezeles menube: 5"<<std::endl;

        is >>f_valasztas;

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

        switch(f_valasztas){
        case 1:
            //system("cls");
            konyv.AlapFelvesz();
            break;
        case 2:
            //system("cls");
            konyv.UzletiFelvesz();
            break;
        case 3:
            //system("cls");
            konyv.DiakFelvesz();
            break;
        case 4:
            //system("cls");
            konyv.NyugdijasFelvesz();
            break;
        case 5:
            //system("cls");
            break;
        default:
            std::cout<<"Nincsen ilyen menupont"<<std::endl;
            break;
        }
    }while(f_valasztas != 5);
}
