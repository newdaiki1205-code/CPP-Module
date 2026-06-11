#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
    public:
        HumanA(std::string name, Weapon &weapon)
            :weaponType(weapon), personName(name){};
        ~HumanA(){};
        void attack();
    
    private:
        Weapon &weaponType;
        std::string personName;
};

#endif