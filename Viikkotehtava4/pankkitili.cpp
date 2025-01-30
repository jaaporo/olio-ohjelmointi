#include "pankkitili.h"
#include <iostream>
#include <string>

using namespace std;
Pankkitili::Pankkitili(string nimi):omistaja(nimi), saldo(0)
{

}

double Pankkitili::getBalance() const
{
    return saldo;
}

bool Pankkitili::deposit(double amount)
{
    if (amount<=0) return false;
    saldo+=amount;
    cout<<"Pankkitili talletus "<<amount<<" tehty"<<endl;
    return true;
}

bool Pankkitili::withdraw(double amount)
{
    if (amount <= 0) {
        cout << "Virhe: Nostosumma ei voi olla negatiivinen."<<endl;
        return false;
    }
    if (saldo < amount) {
        cout << "Virhe: Nostettava summa ylittää pankkitilin saldon"<<endl;
        return false;
    }
    saldo -= amount;
    cout << "Pankkitili: nosto " << amount << "€ tehty"<<endl;
    return true;
}

bool Pankkitili::tiliSiirto(double amount, Pankkitili &recipient)
{
    if (amount <= 0) {
        cout << "Virhe: Siirrettävä summa ei voi olla negatiivinen tai nolla." << endl;
        return false;
    }
    if (saldo < amount) {
        cout << "Virhe: Ei tarpeeksi saldoa siirtoon." << endl;
        return false;
    }
    saldo -= amount;  // Vähennetään siirrettävä summa lähtötililtä
    recipient.deposit(amount);  // Siirretään rahat vastaanottajalle
    cout << "Siirto onnistui, " << amount << "€ siirretty tilille " << recipient.getBalance()<< ". Uusi saldo: " << recipient.getBalance() << "€" << endl;
    return true;

}

