#include "notifikaattori.h"
#include "seuraaja.h"
#include <iostream>
using namespace std;
Notifikaattori::Notifikaattori()
{
    seuraaja = nullptr;
}

void Notifikaattori::lisaa(Seuraaja* uusiSeuraaja)
{
    if(!uusiSeuraaja) return;
    uusiSeuraaja->next = seuraaja;
    seuraaja = uusiSeuraaja;

}

void Notifikaattori::poista(Seuraaja* poistettava)
{
    if(!seuraaja||!poistettava) return;
    if (seuraaja==poistettava){
        seuraaja = seuraaja->next;
        return;
    }
    Seuraaja* nykyinen = seuraaja;
    while (nykyinen->next &&nykyinen->next !=poistettava){ //logical AND
        nykyinen = nykyinen->next;
    }
    if(nykyinen->next){
        nykyinen->next = nykyinen->next->next;
    }
}

void Notifikaattori::tulosta()
{
    Seuraaja* seuraajalista = seuraaja;
    while (seuraajalista){
        cout<<seuraajalista->getNimi();
        if(seuraajalista->next)cout<<"->";
        seuraajalista=seuraajalista->next;
    }
    cout<<"nullptr"<<endl;
}

void Notifikaattori::postita(string viesti)
{
    Seuraaja* seuraajalista = seuraaja;
    while (seuraajalista){
        seuraajalista->paivitys(viesti);
        seuraajalista=seuraajalista->next;
    }
}

