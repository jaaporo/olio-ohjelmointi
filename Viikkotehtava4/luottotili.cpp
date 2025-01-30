#include "luottotili.h"

#include <iostream>
#include <string>
using namespace std;
Luottotili::Luottotili(string nimi, double luottoraja) :Pankkitili(nimi)
{
    this->luottoraja=-luottoraja;
    cout<<"Pankkitili luotu "<<nimi<<":lle"<<endl;
    cout<<"Luottotili luotu "<<nimi<<":lle, luottoraja "<<luottoraja<<endl;
}

bool Luottotili::deposit(double amount)
{
    if (amount<=0) return false;
    saldo += amount;
    if (saldo>0) saldo=0;
    cout<<"Luottotili: maksettu "<<amount<<" velkaa jäljellä "<< saldo<<endl;
    return true;
}

bool Luottotili::withdraw(double amount)
{
    if (amount<= 0 || saldo - amount < luottoraja) return false;
    saldo -=amount;
    cout<<"Luottotili: nosto "<<amount<<" tehty, luottoa jäljellä "<<saldo<<endl;
    return true;
}

double Luottotili::getLuottoJaljella() const
{
    return luottoraja - saldo;

}

