#include "chef.h"
#include <iostream>
using namespace std;

Chef::Chef(const string& name): chefName(name)
{
    cout<<"Chef constructor: "<<chefName<<endl;
}

Chef::~Chef()
{
    cout<<"Chef destructor: "<<chefName<<endl;
}

string Chef::getName()
{
    return chefName;
}

int Chef::makeSalad(int ingredients)
{
    cout<<chefName<<" is making salad with"<<ingredients<<endl;
    return ingredients/5;
}

int Chef::makeSoup(int ingredients)
{
    cout<<chefName<<" is making soup with"<<ingredients<<endl;
    return ingredients/3;
}
