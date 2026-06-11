#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
    public:
        HumanB(std::string name)
            :personName(name){};
        ~HumanB(){};
        void attack();
        void setWeapon(Weapon &weapon);
    
    private:
        Weapon *weaponType;
        std::string personName;
};

#endif

