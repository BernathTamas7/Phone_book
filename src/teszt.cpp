#ifdef TESZT

#include "gtest_lite.h"
#include "telefonkonyv.hpp"
#include "alap.hpp"
#include "diak.hpp"
#include "nyugdijas.hpp"
#include "uzleti.hpp"


#include <iostream>
#include <string>

int main(){
    ///getter-setter*******************

    ///Alap osztaly
    TEST(AlapOsztaly, getset){
        Alap t;
        t.setMarka("Samsung");
        EXPECT_EQ("Samsung", t.getMarka()) << "Nem jo a marka allitasa!";
    } END

    ///Diak osztaly
    TEST(DiakOsztalyIsk, getset){
        Diak t;
        t.setIskola("Paksi Vak Bottyan Iskola");
        EXPECT_EQ("Paksi Vak Bottyan Iskola", t.getIskola()) << "Nem jo az iskola allitasa!";
    } END

    ///Diak osztaly
    TEST(DiakOsztalyEvf, getset){
        Diak t;
        t.setEvfolyam(12);
        EXPECT_EQ(12, t.getEvfolyam()) << "Nem jo az evfolyam allitasa!";
    } END

    ///Nev osztaly
    TEST(NevOsztalyVezetek, getset){
        Nev t;
        t.setVezetek("Bernath");
        EXPECT_EQ("Bernath", t.getVezetek()) << "Nem jo a Vezeteknev allitasa!";
    } END

    ///Nev osztaly
    TEST(NevOsztalyKereszt, getset){
        Nev t;
        t.setKereszt("Tamas");
        EXPECT_EQ("Tamas", t.getKereszt()) << "Nem jo a Keresztnev allitasa!";
    } END

    ///Cim osztaly
    TEST(CimOsztalyIrszam, getset){
        Cim t;
        t.setIrszam(7030);
        EXPECT_EQ(7030, t.getIrszam()) << "Nem jo az iranyitoszam allitasa!";
    } END

    ///Cim osztaly
    TEST(CimOsztalyUtca, getset){
        Cim t;
        t.setUtca("Vadasz utca");
        EXPECT_EQ("Vadasz utca", t.getUtca()) << "Nem jo az utca allitasa!";
    } END

    ///Konstruktorok*****************


    ///Nev osztaly
    TEST(NevOsztaly, konstruktor){
        Nev t("Bernath", "Tamas", "Tomi");
        EXPECT_EQ("Bernath",t.getVezetek()) << "Nem jo az Nev konstruktor!";
        EXPECT_EQ("Tamas",t.getKereszt()) << "Nem jo az Nev konstruktor!";
        EXPECT_EQ("Tomi",t.getBece()) << "Nem jo az Nev konstruktor!";
    } END

    ///Cim osztaly
    TEST(CimOsztaly, konstruktor){
        Cim t(7030, "Paks", "Vadasz utca", 57);
        EXPECT_EQ(7030,t.getIrszam()) << "Nem jo az Cim konstruktor!";
        EXPECT_EQ("Paks",t.getVaros()) << "Nem jo az cim konstruktor!";
        EXPECT_EQ("Vadasz utca",t.getUtca()) << "Nem jo az cim konstruktor!";
        EXPECT_EQ(57,t.getHazszam()) << "Nem jo az cim konstruktor!";
    } END

    ///Telefonszam osztaly
    TEST(TelefonszamOsztaly, konstruktor){
        Telefonszam t("0622222", "0611111");
        EXPECT_EQ("0622222",t.getMunk()) << "Nem jo az telefonszam konstruktor!";
        EXPECT_EQ("0611111",t.getPriv()) << "Nem jo az telefonszam konstruktor!";
    } END

    ///Alap osztaly
    TEST(AlapOsztaly, konstruktor){
        Alap t;
        t.setNev("Bernath", "Tamas", "Tomi");
        t.setCim(7030, "Paks", "Vadasz utca", 57);
        t.setTelefon("1234567", "7654321");
        t.setMarka("Samsung");

        EXPECT_EQ("Bernath", t.getNev().getVezetek()) << "Alap konstruktor hiba";
        EXPECT_EQ("Tamas", t.getNev().getKereszt()) << "Alap konstruktor hiba";
        EXPECT_EQ("Tomi", t.getNev().getBece()) << "Alap konstruktor hiba";
        EXPECT_EQ(7030, t.getCim().getIrszam()) << "Alap konstruktor hiba";
        EXPECT_EQ("Paks", t.getCim().getVaros()) << "Alap konstruktor hiba";
        EXPECT_EQ("Vadasz utca", t.getCim().getUtca()) << "Alap konstruktor hiba";
        EXPECT_EQ(57, t.getCim().getHazszam()) << "Alap konstruktor hiba";
        EXPECT_EQ("1234567", t.getTelefon().getMunk()) << "Alap konstruktor hiba";
        EXPECT_EQ("7654321", t.getTelefon().getOtth()) << "Alap konstruktor hiba";
        EXPECT_EQ("Samsung", t.getMarka());
    } END


    ///Diak osztaly
    TEST(DiakOsztaly, konstruktor){
        Diak t;
        t.setNev("Bernath", "Tamas", "Tomi");
        t.setCim(7030, "Paks", "Vadasz utca", 57);
        t.setTelefon("1234567", "7654321");
        t.setIskola("BME");
        t.setEvfolyam(1);

        EXPECT_EQ("Bernath", t.getNev().getVezetek()) << "Diak konstruktor hiba";
        EXPECT_EQ("Tamas", t.getNev().getKereszt()) << "Diak konstruktor hiba";
        EXPECT_EQ("Tomi", t.getNev().getBece()) << "Diak konstruktor hiba";
        EXPECT_EQ(7030, t.getCim().getIrszam()) << "Diak konstruktor hiba";
        EXPECT_EQ("Paks", t.getCim().getVaros()) << "Diak konstruktor hiba";
        EXPECT_EQ("Vadasz utca", t.getCim().getUtca()) << "Diak konstruktor hiba";
        EXPECT_EQ(57, t.getCim().getHazszam()) << "Diak konstruktor hiba";
        EXPECT_EQ("1234567", t.getTelefon().getMunk()) << "Diak konstruktor hiba";
        EXPECT_EQ("7654321", t.getTelefon().getOtth()) << "Diak konstruktor hiba";
        EXPECT_EQ("BME", t.getIskola()) << "Diak konstruktor hiba";
        EXPECT_EQ(1, t.getEvfolyam()) << "Diak konstruktor hiba";
    } END

    ///Tarolo********************

    ///Felvesz
    TEST(Tarolo, felvesz){
        SajatVektor<Szemely*> t;
        t.felvesz(new Alap());
        EXPECT_GT(t.getMeret(),0u);
    } END

    ///Torol
    TEST(Tarolo, Torol){
        SajatVektor<Szemely*> t;
        t.felvesz(new Alap());
        t.Torol(0);
        EXPECT_EQ(0u, t.getMeret()) << "Sajatvektor torol hiba";
    } END

    ///Telefonkonyv*****************

    ///Felvetel
    TEST(Telefonkonyv, Felvetel){
        Telefonkonyv t;
        t.Felvesz(new Alap());
        EXPECT_EQ(1u, t.getMeret()) << "Telefonkonyv felvetel hiba";
    } END

    ///Torol
    TEST(Telefonkonyv, Torles){
        Telefonkonyv t;
        t.Felvesz(new Alap());
        t.Torol_index(0);
        EXPECT_EQ(0u, t.getMeret()) << "Telefonkonyv torles hiba";
    } END

    ///Kereses
    TEST(Telefonkonyv, Keres){
        Telefonkonyv t;
        Diak* d = new Diak(Nev("Kiss", "Anna", "Ani"), Cim(), Telefonszam(), "BME", 1);
        t.Felvesz(d);
        Szemely* talalt = t.Keres("Kiss", "Anna", "Ani");
        EXPECT_TRUE(talalt != nullptr) << "Telefonkonyv keres hiba";
        EXPECT_EQ("Kiss", talalt->getNev().getVezetek());
    } END
}
#endif
