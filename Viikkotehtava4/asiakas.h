#ifndef ASIAKAS_H
#define ASIAKAS_H
#include <string>
#include <iostream>
#include "pankkitili.h"
#include "luottotili.h"
using namespace std;

class Asiakas
{
public:
    Asiakas(string nimi, double luottoraja);
    string getNimi() const;
    void showSaldo() const;
    bool talletus(double amount);
    bool nosto(double amount);
    bool luotonMaksu(double amount);
    bool luotonNosto(double amount);
    bool tiliSiirto(double amount, Asiakas &toCustomer);

private:
    string nimi;
    Pankkitili kayttotili;
    Luottotili luottotili;

};

#endif // ASIAKAS_H
