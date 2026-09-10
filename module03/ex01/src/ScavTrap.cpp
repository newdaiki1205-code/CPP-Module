#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap's Constructor called, hello " << Name << std::endl;
	HP = 100;
	EP = 50;
	AD = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap's Copy Constructor called.";
	std::cout << " Hello, " << Name << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
  std::cout << "ScavTrap's Copy Assignement operator called." << std::endl;
	if (this != &other)
	{
		Name = other.getName();
		HP = other.getHP();
		EP = other.getEP();
		AD = other.getAD();
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap's Destructor called, byebye " << Name << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (!areYouAlive())
	{
		std::cout << "ScavTrap " << this->Name << " cannot attack..." << std::endl;
		showStatus();
		return ;
	}
	std::cout << "ScavTrap " << this->Name << " attacks " << target << " causing " << this->AD << " points of damage!" << std::endl;
	this->EP--;
	showStatus();
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gatekeeper mode." << std::endl;
}
