#include "HumanA.hpp"

void HumanA::attack()
{
    std::cout << personName << " attacks with their " << weaponType.getType() << std::endl;
}
