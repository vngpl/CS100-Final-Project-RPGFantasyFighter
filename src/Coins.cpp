#include "../header/Coins.hpp"
// #include "../header/Monster.hpp" NEED MONSTER HP TO CAUSE COINS TO BE ADDED
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time() MAKES SURE ITS ALWAYS RANDOM SO THAT EVEN IF YOU HAVE A SAME SEED ITS STILL RANDOM

using namespace std;

Coins::Coins(int minCoins, int maxCoins) //Character* character
    : amountCoins(0), minCoins(minCoins), maxCoins(maxCoins) {
    //character->getCoins()
    //Set RNG
    srand(static_cast<unsigned>(std::time(0)));
}

void Coins::addCoinsOnMONSERdeath() {
    int monsterHP = enemy->getHealth();
    
    if (monsterHP <= 0) {
        int coinsDropped = minCoins + std::rand() % (maxCoins - minCoins + 1);
        amountCoins += coinsDropped;
        character->setCoins(amountCoins);
    }
}

// int Coins::getCoins() const {return }

int Coins::getAmountCoins() const { return amountCoins; }

int Coins::setUpdateCoins(int newCoins) { newCoins = amountCoins; }

// int coinsDropped = minCoins + std::rand() % (maxCoins - minCoins + 1);
// amountCoins += coinsDropped;
