

#ifndef SAJATVEKTOR_HPP
#define SAJATVEKTOR_HPP

#include <iostream>

template <typename T>
class SajatVektor {
    T* tomb;
    int meret;
    int kapacitas;

    //kapacitas noveleseert felelos fuggveny, privat
    void kap_nov() {
        int ujkap = 0;
        if (kapacitas == 0){
            ujkap =2;
        }
        else{
            ujkap = kapacitas*2;
        }
        T* uj = new T[ujkap];
        for (int i = 0; i < meret; ++i){
            uj[i] = tomb[i];
        }
        delete[] tomb;
        tomb = uj;
        kapacitas = ujkap;
    }

public:
    SajatVektor() : tomb(nullptr), meret(0), kapacitas(0) {}

    ~SajatVektor() {
        for (int i = 0; i < meret; ++i){
            delete tomb[i];
        }
        delete[] tomb;
    }

    //elemet vesz fel a taroloba, ha nincs eleg hely akkor elotte boviti a kapacitast
    void Felvesz(T elem) {
        if (meret >= kapacitas){
            kap_nov();
        }
        tomb[meret++] = elem;
    }

    //elemet torol a tarolobol
    void Torol(int index) {
        if (index < 0 || index >= meret) return;
        delete tomb[index];
        for (int i = index; i < meret - 1; ++i)
            tomb[i] = tomb[i + 1];
        --meret;
    }

    //elenet lehet modositani vele a taroloban
    void Modosit(int index, T uj) {
        if (index < 0 || index >= meret) return;
        delete tomb[index];
        tomb[index] = uj;
    }

    //visszaadja a tarolo elso elemere mutato pointert
    T* getElements() const {
        return tomb;
    }

    //visszaadja a tarolo meretet
    int getMeret() const {
        return meret;
    }
};

#endif


