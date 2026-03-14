#ifndef TESZT

#include <iostream>

#include "telefonkonyv.hpp"
#include "diak.hpp"
#include "nyugdijas.hpp"
#include "alap.hpp"
#include "fomenu.hpp"
#include "uzleti.hpp"




int main()
{


    Telefonkonyv konyv;

    Diak* d = new Diak(Nev("Kiss", "Anna", "Ani"), Cim(1111, "Budapest", "Petofi utca", 1), Telefonszam("123", "456"), "BME", 2);
    Nyugdijas* n = new Nyugdijas(Nev("Nagy", "Bela", "Beni"), Cim(2222, "Debrecen", "Arany J. u.", 3), Telefonszam("789", "012"), 2000, true);
    Alap* a = new Alap(Nev("Toth", "Geza", "Gezu"), Cim(3333, "Szeged", "Kossuth Lajos u.", 4), Telefonszam("333", "444"), "Samsung");
    Uzleti* u = new Uzleti(Nev("Szabo", "Erika", "Eri"), Cim(4444, "Pecs", "Rakoczi ut", 5), Telefonszam("555", "666"), Cim(4445, "Pecs", "Uranvaros", 2));

    konyv.Felvesz(d);
    konyv.Felvesz(n);
    konyv.Felvesz(a);
    konyv.Felvesz(u);

    Fajlkezeles fajl;


    fomenu(konyv,std::cin, std::cout,fajl);
    return 0;
}

#endif
