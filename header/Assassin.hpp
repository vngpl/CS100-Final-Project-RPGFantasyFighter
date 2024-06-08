#ifndef __ASSASSIN_HPP_
#define __ASSASSIN_HPP_

class Assassin : public Character {
    private:
    
    public:
        Assassin();
        std::string getType() const override;
};

#endif
