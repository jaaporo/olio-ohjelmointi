#ifndef ITALIANCHEF_H
#define ITALIANCHEF_H
#include "chef.h"
#include <string>
using namespace std;

class ItalianChef : public Chef
{
public:
    ItalianChef(const string& name);
    ~ItalianChef();
    bool askSecret(int, int);
protected:
private:
    string password="pizza";
    int makePizza(int flour, int water);
};

#endif // ITALIANCHEF_H
