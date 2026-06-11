#include "HumanB.hpp"

void HumanB::attack()
{
    std::cout << personName << " attacks with their " << weaponType->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    weaponType = &weapon;
}