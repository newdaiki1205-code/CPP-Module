#include "../include/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string givenName) : ClapTrap(givenName
	+ "_clap_name"), ScavTrap(givenName), FragTrap(givenName)
{
	std::cout << "DiamondTrap's Constructor called" << std::endl;
	name = givenName;
	this->EP = 50;
	std::cout << "[INFO] Name: " << name << " HP: " << this->HP << " EP: " << this->EP << " AD: " << this->AD << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other),
	ScavTrap(other), FragTrap(other)
{
	std::cout << "DiamondTrap's Copy Constructor called" << std::endl;
	name = other.name;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		name = other.name;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap's Destructor called, byebye" << name << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "My name is " << name << "." << std::endl;
	std::cout << "My base name is " << ClapTrap::Name << "." << std::endl;
}
