#ifndef CIM_HPP
#define CIM_HPP

#include <iostream>
#include <string>

using namespace std;

class Cim{
    int ir_szam;
    string varos;
    string utca;
    int hazszam;
public:
    Cim(): ir_szam(0), varos(""), utca(""), hazszam(0){}
    Cim(int irszam, const string& varos, const string& utca, int hazszam): ir_szam(irszam), varos(varos), utca(utca), hazszam(hazszam){}

    int GetIrszam() const;
    string GetVaros() const;
    string GetUtca() const;
    int GetHazszam() const;

    void setIrszam(int tmp);
    void setVaros(string tmp);
    void setUtca(string tmp);
    void setHazszam(int tmp);

    void kiir() const;
    friend ostream& operator<<(ostream& os, const Cim& cim);
};

#endif
