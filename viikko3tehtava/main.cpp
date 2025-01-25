#include <iostream>
#include"chef.h"
#include "italianchef.h"

using namespace std;

int main()
{
    Chef chef("Purre");
    cout<<chef.getName()<<" is ready to cook ";
    int salads=chef.makeSalad(20);
    int soups=chef.makeSoup(15);
    cout<<chef.getName()<<" made "<<salads<<" salads and "<< soups<<" soups.";
    ItalianChef italianChef("Turre");
    int flour = 20;
    int water = 15;

    italianChef.askSecret(20,15);
    italianChef.askSecret(10,10);


    return 0;
}

