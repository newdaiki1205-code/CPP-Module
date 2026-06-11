#ifndef WEAPON_H
# define WEAPON_H

#include <iostream>

class Weapon
{
    public:
        Weapon(){};
        Weapon(std::string weapon);
        ~Weapon(){};
        const std::string &getType();
        void setType(std::string str);

    private:
        std::string type;
};

#endif