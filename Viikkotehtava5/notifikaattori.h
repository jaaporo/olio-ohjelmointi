#ifndef NOTIFIKAATTORI_H
#define NOTIFIKAATTORI_H
#include "seuraaja.h"
#include <iostream>
using namespace std;
class Notifikaattori
{
public:
    Notifikaattori();
    void lisaa(Seuraaja *uusiSeuraaja);
    void poista(Seuraaja *poistettava);
    void tulosta();
    void postita(string viesti);

private:
  Seuraaja* seuraaja = nullptr;
};

#endif // NOTIFIKAATTORI_H
