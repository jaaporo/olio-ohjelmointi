#ifndef SEURAAJA_H
#define SEURAAJA_H
#include <iostream>
using namespace std;
class Seuraaja
{
public:
    Seuraaja(string nimi);
   Seuraaja* next=nullptr;
    string getNimi();
    void paivitys(string viesti);

private:
    string nimi;
};

#endif // SEURAAJA_H
