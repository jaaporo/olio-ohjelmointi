#include "asiakas.h"
#include "pankkitili.h"
#include "luottotili.h"
#include <iostream>
using namespace std;
Asiakas::Asiakas(string nimi, double luottoraja):nimi(nimi),kayttotili(nimi),luottotili(nimi,luottoraja)
{

    cout<<"Asiakkuus luotu "<<nimi<<endl;
    showSaldo();
}

string Asiakas::getNimi() const
{
    return nimi;
}

void Asiakas::showSaldo() const
{
    cout<<nimi<<endl;
    cout<<"Pankkitilin saldo: "<<kayttotili.getBalance()<<"€"<<endl;
    cout<<"Luottotilin saldo: "<<luottotili.getBalance()<<"€"<<endl;
    cout<<"Luottotilin jaljella oleva luotto: "<<luottotili.getLuottoJaljella()<<"€"<<endl;


}

bool Asiakas::talletus(double amount)
{
    return kayttotili.deposit(amount);
}

bool Asiakas::nosto(double amount)
{
    return kayttotili.withdraw(amount);
}

bool Asiakas::luotonMaksu(double amount)
{
    return luottotili.deposit(amount);
}

bool Asiakas::luotonNosto(double amount)
{
    return luottotili.withdraw(amount);
}

bool Asiakas::tiliSiirto(double amount, Asiakas &toCustomer)
{
    // Siirto tapahtuu vain pankkitililtä pankkitilille
    if (kayttotili.tiliSiirto(amount, toCustomer.kayttotili)) {
        cout << "Siirto onnistui asiakkaalta " << getNimi() << " asiakkaalle " << toCustomer.getNimi() << endl;
        return true;
    } else {
        cout << "Siirto epäonnistui." << endl;
        return false;
    }
}
