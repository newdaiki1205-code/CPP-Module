#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string givenName) : ClapTrap(givenName), ScavTrap(givenName), FragTrap(givenName)
{
    std::cout << "DiamondTrap's Constructor called" << std::endl;
}