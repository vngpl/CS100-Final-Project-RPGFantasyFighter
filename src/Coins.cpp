#include "../header/Coins.hpp"
// #include "../header/Monster.hpp" NEED MONSTER HP TO CAUSE COINS TO BE ADDED
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time() MAKES SURE ITS ALWAYS RANDOM SO THAT EVEN IF YOU HAVE A SAME SEED ITS STILL RANDOM

using namespace std;

Coins::Coins(int minCoins, int maxCoins) 
    : amountCoins(0), minCoins(minCoins), maxCoins(maxCoins) {
    //Set RNG
    srand(static_cast<unsigned>(std::time(0)));
}

void Coins::addCoinsOnMONSERdeath() {
    // if (monsterHP <= 0) {
        int coinsDropped = minCoins + std::rand() % (maxCoins - minCoins + 1);
        amountCoins += coinsDropped;
    // }
}

int Coins::getAmountCoins() const {
    return amountCoins;
}

