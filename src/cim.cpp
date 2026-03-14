#include "cim.hpp"

#include <iostream>
#include <string>


using namespace std;

///getter-setter fuggvenyek

int Cim::GetIrszam() const{
    return ir_szam;
}

string Cim::GetVaros() const{
    return varos;
}
string Cim::GetUtca() const{
    return utca;
}
int Cim::GetHazszam() const{
    return hazszam;
}

void Cim::setIrszam(int tmp){
    ir_szam = tmp;
}
void Cim::setVaros(string tmp){
    varos = tmp;
}
void Cim::setUtca(string tmp){
    utca = tmp;
}
void Cim::setHazszam(int tmp){
    hazszam = tmp;
}
///-----------------------

//a cim szep kiirasaert felel
void Cim::kiir() const{
    cout << ir_szam << " " << varos << ", " << utca << " " << hazszam << endl;
}

//operator tulterheles
ostream& operator<<(ostream& os, const Cim& cim) {
    os << cim.ir_szam << " " << cim.varos << ", " << cim.utca << " " << cim.hazszam;
    return os;
}
