#ifndef PANKKITILI_H
#define PANKKITILI_H

#include <string>
using namespace std;
class Pankkitili
{
public:
    Pankkitili(string nimi);
    virtual ~Pankkitili()=default;
    double getBalance() const;
    virtual bool deposit(double amount);
    virtual bool withdraw(double amount);
    bool tiliSiirto(double amount, Pankkitili &recipient);

protected:
    string omistaja;
    double saldo=0;
};

#endif // PANKKITILI_H
