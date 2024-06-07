#ifndef __DISPLAY_HPP__
#define __DISPLAY_HPP__

#include <iostream>
#include <string>

class Display {
	public:
        static void printIntro();
        static void printInvalidInput();
        static void printCharacterCreation();
        static void printSettings();
        static void printQuit();
        static void printStats();

        //Print function headers for Item classes 
        static void printEmptyInventory();
        static void printFilledInventory();

        static void printUseSword();
        static void printUseDagger();
        static void printUseWand();
        static void printUseAttackPotion();
        static void printUseHealthPotion();

        static void printShopItemGeneration();
        static void printItemBuyFail();
        static void printItemBuyPass();  

};


#endif
