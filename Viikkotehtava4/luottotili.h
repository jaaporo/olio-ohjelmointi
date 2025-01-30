#ifndef LUOTTOTILI_H
#define LUOTTOTILI_H
#include "pankkitili.h"

#include <string>
using namespace std;

class Luottotili : public Pankkitili
{
public:
    Luottotili(string nimi, double luottoraja);
    bool deposit(double) override;
    bool withdraw(double) override;
    double getLuottoJaljella() const;
protected:
    double luottoraja=0;

};

#endif // LUOTTOTILI_H
