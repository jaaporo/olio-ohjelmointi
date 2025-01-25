#ifndef CHEF_H
#define CHEF_H
#include <string>
using namespace std;
class Chef
{
public:
    Chef(const string& name); // name on viittaus const sstring- objektiin
    ~Chef();
    string getName();
    int makeSalad(int ingredients);
    int makeSoup(int ingredients);

protected:
    string chefName;

};

#endif // CHEF_H
