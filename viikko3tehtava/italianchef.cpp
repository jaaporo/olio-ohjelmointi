#include "italianchef.h"
#include <string>
#include <iostream>
#include <algorithm>
#include"chef.h"
using namespace std;

ItalianChef::ItalianChef(const string& name):Chef(name),password("pizza")
{
    cout<<"ItalianChef constructor: "<<chefName<<endl;
}

ItalianChef::~ItalianChef()
{
    cout<<"ItalianChef destructor: "<<chefName<<endl;
}

bool ItalianChef::askSecret(int flour, int water)
{
    string inputPassword;
    cout<<"Enter password: "<<endl;
    cin>>inputPassword;

    if(inputPassword==password){
        cout<<"password accepted. preparing pizza."<<endl;
        makePizza(flour,water);
        return true;
    }else{
        cout<<"password incorrect"<<endl;
        return false;
    }

}

int ItalianChef::makePizza(int flour, int water)
{
    int pizzas=min(flour/5, water/5);
    cout<<"prepared "<<pizzas<<" pizzas"<<endl;
}
