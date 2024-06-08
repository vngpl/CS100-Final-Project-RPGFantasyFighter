#ifndef __WARRIOR_HPP_
#define __WARRIOR_HPP_

class Warrior : public Character {
    private:
    
    public:
        Warrior();
        std::string getType() const override;
};

#endif