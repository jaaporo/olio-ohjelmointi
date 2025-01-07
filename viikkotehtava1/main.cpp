#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int game(int maxnum){
    srand(time(0));
    int luku = rand() % maxnum + 1;
    int arvaus;
    int arvaustenmaara=0;
    while(true){
        arvaustenmaara++;
        cout<<"arvaa luku: ";
        cin>>arvaus;
        if(arvaus<luku){
            cout<<"luku on suurempi"<<endl;
        } else if(arvaus>luku){
            cout << "Luku on pienempi." << endl;
        } else {
            cout << "Oikea vastaus!" << endl;
            break;
        }

    }
    return arvaustenmaara;
}

int main()
{
    int maxnum = 40;
    int arvaustenmaara = game(maxnum);
    cout << "Arvasit " << arvaustenmaara << " kertaa." << endl;
    return 0;
}


