#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time() MAKES SURE ITS ALWAYS RANDOM SO THAT EVEN IF YOU HAVE A SAME SEED ITS STILL RANDOM

#ifndef __COINS_HPP__
#define __COINS_HPP__

#include "../header/Character.hpp"
#include "../header/Enemy.hpp"

using namespace std;

class Coins {
    private:
        int amountCoins;
        int minCoins;
        int maxCoins;
        Character* character;
        Enemy* enemy;
    public:
        // CONSTRUCTOR TO INITIALIZE THE COIN AMOUNT TO 0
        // Coins () {}
        Coins(int minCoins = 1, int maxCoins = 10); //Character* character

        // WHEN MONSTER DIES RANDOM 3-10 COINS WILL BE ADDED
        void addCoinsOnMONSERdeath();
        int getAmountCoins() const;
        int setUpdateCoins(int);

};

#endif // COINS_HPP