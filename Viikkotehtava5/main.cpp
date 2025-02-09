#include "notifikaattori.h"
#include "seuraaja.h"
#include <iostream>

using namespace std;

int main()
{
    Notifikaattori n;

    Seuraaja a("A");
    Seuraaja b("B");
    Seuraaja c("C");

    n.lisaa(&a);
    n.lisaa(&b);
    n.lisaa(&c);
    n.tulosta();

    n.postita("Viesti numero 1");
    n.poista(&b);
    n.postita("Viesti numero 2");
    return 0;
}
