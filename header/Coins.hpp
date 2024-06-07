#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time() MAKES SURE ITS ALWAYS RANDOM SO THAT EVEN IF YOU HAVE A SAME SEED ITS STILL RANDOM

#ifndef __COINS_HPP__
#define __COINS_HPP__

using namespace std;

class Coins {
    private:
        int amountCoins;
        int minCoins;
        int maxCoins;
    public:
        // CONSTRUCTOR TO INITIALIZE THE COIN AMOUNT TO 0
        Coins(int minCoins = 3, int maxCoins = 10);

        // WHEN MONSTER DIES RANDOM 3-10 COINS WILL BE ADDED
        void addCoinsOnMONSERdeath();
        int getAmountCoins() const;
};

#endif // COINS_HPP