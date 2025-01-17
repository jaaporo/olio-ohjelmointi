#include "game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Game::Game(int maxNumberParam)
{
    maxNumber = maxNumberParam;
    numOfGuesses=0;
    std::srand(std::time(0));
    randomNumber = std::rand()%maxNumber +1;
}

Game::~Game()
{

}

void Game::play()
{
    int playerGuess = 0;
    std::cout<<"Arvaa luku 1- "<<maxNumber<<":"<<std::endl;

    while(playerGuess != randomNumber){
        std::cout<<"Arvaa luku: ";
        std::cin>>playerGuess;
        numOfGuesses++;

        if(playerGuess < randomNumber){
            std::cout<<"luku on suurempi."<<std::endl;

        } else if(playerGuess > randomNumber){
            std::cout<<"luku on pienempi."<<std::endl;
        }else{
            std::cout<<"oikea vastaus."<<std::endl;
            printGameResult();
        }
    }
}

void Game::printGameResult()
{
    std::cout<<"Arvasit oikein. Oikea luku on: "<<randomNumber<<std::endl;
    std::cout<<"Arvauksia yhteensä: "<<numOfGuesses<<std::endl;
}
