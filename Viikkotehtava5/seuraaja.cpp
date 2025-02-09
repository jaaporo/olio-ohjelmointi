#include "seuraaja.h"

Seuraaja::Seuraaja(string nimi)
{
    this->nimi=nimi;
    this->next=nullptr;
}

string Seuraaja::getNimi()
{
    return nimi;
}

void Seuraaja::paivitys(string viesti)
{
    cout<<"Seuraaja "<<nimi<<" sai viestin: "<<viesti<<endl;
}
