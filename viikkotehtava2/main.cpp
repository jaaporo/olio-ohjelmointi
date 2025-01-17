#include <iostream>
#include "game.h"
//using namespace std;

int main()
{
    int maxNumber;
    //std::cout<<"syota pelin maksimiluku:";
    //std::cin>>maxNumber;
    maxNumber = 10;

    if(maxNumber <=1){

        return 1;
    }

    Game peli(maxNumber);
    peli.play();
    return 0;
}
