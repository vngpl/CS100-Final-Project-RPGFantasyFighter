#include "../header/Coins.hpp"
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time() MAKES SURE ITS ALWAYS RANDOM SO THAT EVEN IF YOU HAVE A SAME SEED ITS STILL RANDOM

using namespace std;

Coins::Coins(int minCoins, int maxCoins)
    : amountCoins(0), minCoins(minCoins), maxCoins(maxCoins) {
    //character->getCoins()
    //Set RNG
    srand(static_cast<unsigned>(std::time(0)));
}

void Coins::addCoinsOnMONSERdeath(int monsterHP) {
    if (monsterHP <= 0) {
        int coinsDropped = minCoins + std::rand() % (maxCoins - minCoins + 1);
        amountCoins += coinsDropped;
    }
}

// int Coins::getCoins() const {return }

int Coins::getAmountCoins() const { return amountCoins; }

void Coins::setUpdateCoins(int newCoins) { 
    amountCoins = newCoins; 
}


// int coinsDropped = minCoins + std::rand() % (maxCoins - minCoins + 1);
// amountCoins += coinsDropped;
