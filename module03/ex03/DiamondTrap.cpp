#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string givenName) : ClapTrap(givenName), ScavTrap(givenName), FragTrap(givenName)
{
    std::cout << "DiamondTrap's Constructor called" << std::endl;
    name = ClapTrap::Name + "_clap_name";
    EP = 50;
    showStatus();
}

DiamondTrap::DiamondTrap(const DiamondTrap& other): ClapTrap(other), ScavTrap(other), FragTrap(other)
{
    std::cout << "DiamondTrap's Copy Constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if(this != &other)
    {
        Name = other.Name;
        HP = other.HP;
        EP = other.EP;
        AD = other.AD;
        name = other.name;
    }
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap's Destructor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "My name is " << Name << "." << std::endl;
    std::cout << "My base name is " << name << "." << std::endl;
}