#ifndef TELEFONKONYV_HPP
#define TELEFONKONYV_HPP

#include "szemely.hpp"
#include "sajatvektor.hpp"
#include "diak.hpp"
#include "alap.hpp"
#include "nyugdijas.hpp"
#include "uzleti.hpp"

#include <iostream>
#include <string>

class Telefonkonyv{
    SajatVektor<Szemely*> Tarolo;
public:
    Telefonkonyv(): Tarolo(){}
    Telefonkonyv(int kap, int meret, Szemely**t){
        for(int i = 0; i < meret; i++){
            Tarolo.Felvesz(t[i]);
        }
    }

    ~Telefonkonyv(){

    }

    void Felvesz(Szemely* s);
    void ListazOsszes(std::ostream& os) const;
    void Torol_index();
    void Torol_nev();   /// Kész
    void KeresNev() const; /// Kész
    void KeresSzam() const; /// Kész
    void Modosit(); ///Kész
    void SzuresAlapjan(const std::string& mi ,std::ostream& os) const;
    void Rendez(const std::string& szempont); /// Kész
    int getMeret() const;

    void DiakFelvesz();
    void AlapFelvesz();
    void NyugdijasFelvesz();
    void UzletiFelvesz();
    const SajatVektor<Szemely*>& getTarolo() const {
        return Tarolo;
    }
};

#endif
