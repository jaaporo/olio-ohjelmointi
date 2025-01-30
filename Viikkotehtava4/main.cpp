#include <iostream>
#include "asiakas.h"

using namespace std;

int main()
{
    // Luodaan asiakas-oliot
    Asiakas asiakas1("Viima", 10000);
    Asiakas asiakas2("Metti", 10000);

    // Talletetaan rahaa asiakkaille
    asiakas1.talletus(6000);  // Viima tallettaa 5000€
    asiakas2.talletus(1000);  // Metti tallettaa 1000€

    // Näytetään molempien asiakkaiden saldot ennen siirtoa
    cout << "Ennen siirtoa:" << endl;
    asiakas1.showSaldo();  // Näytetään Viiman saldo
    asiakas2.showSaldo();  // Näytetään Metin saldo

    // Siirretään rahaa Viimalta Metille
    asiakas1.tiliSiirto(2000, asiakas2);  // Siirretään 2000 Viimalta Metille

    // Näytetään molempien asiakkaiden saldot siirron jälkeen
    cout << "Siirron jälkeen:" << endl;
    asiakas1.showSaldo();  // Näytetään Viiman saldo
    asiakas2.showSaldo();  // Näytetään Metin saldo

    return 0;

    return 0;
}
