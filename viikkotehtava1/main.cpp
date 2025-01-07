#include <iostream>
#include <cstdlib>
#include <ctime>
//using namespace std;
int game(int maxnum){
    srand(time(0));
    int luku = rand() % maxnum + 1;
    int arvaus;
    int arvaustenmaara=0;
    while(true){
        arvaustenmaara++;
       std::cout<<"arvaa luku: ";
        std::cin>>arvaus;
        if(arvaus<luku){
            std::cout<<"luku on suurempi"<<std::endl;
        } else if(arvaus>luku){
            std::cout << "Luku on pienempi." << std::endl;
        } else {
            std::cout << "Oikea vastaus!" << std::endl;
            break;
        }

    }
    return arvaustenmaara;
}

int main()
{
    int maxnum = 40;
    int arvaustenmaara = game(maxnum);
    std::cout << "Arvasit " << arvaustenmaara << " kertaa." << std::endl;
    return 0;
}


