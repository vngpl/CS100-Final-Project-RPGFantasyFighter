#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <cassert>
#include "Item.hpp"

class Inventory {
    private:
        Item* inventoryItems[2];

    public:
        Inventory();
        
        void addItem(Item *item);
        void useItem(int idx);

        Item* getItem(int); 

        bool IsEmpty() const;
        bool OnlyWeapon() const;
        bool OnlyPotion() const;

};

#endif
