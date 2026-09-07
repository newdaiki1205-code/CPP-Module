#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap() : Name("Unknown"), HP(10), EP(10), AD(0)
{
	std::cout << "Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : Name(name), HP(10), EP(10), AD(0)
{
	std::cout << "ClapTrap's Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : Name(other.Name), HP(other.HP),
	EP(other.EP), AD(other.AD)
{
	std::cout << "Copy Constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->Name = other.Name;
		this->HP = other.HP;
		this->EP = other.EP;
		this->AD = other.AD;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (!areYouAlive())
	{
		std::cout << "ClapTrap " << this->Name << " cannot attack..." << std::endl;
		showStatus();
		return ;
	}
	std::cout << "ClapTrap " << this->Name << " attacks " << target << " causing " << this->AD << " points of damage!" << std::endl;
	this->EP--;
	showStatus();
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->Name << " got " << amount << " damage!" << std::endl;
	for (unsigned int i = 0; i < amount && this->HP > 0; i++)
		this->HP--;
	showStatus();
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!areYouAlive())
	{
		std::cout << "ClapTrap " << this->Name << " cannot be repaired..." << std::endl;
		showStatus();
		return ;
	}
	std::cout << "ClapTrap " << this->Name << " repaired " << amount << "HP!" << std::endl;
	this->HP += amount;
	this->EP--;
	showStatus();
}

bool ClapTrap::areYouAlive()
{
	if (this->EP > 0 && this->HP > 0)
		return (true);
	return (false);
}

void ClapTrap::showStatus()
{
	std::cout << this->Name << " has " << this->HP << " HP and " << this->EP << " EP." << std::endl;
}

std::string ClapTrap::getName() const
{
	return (Name);
}

int ClapTrap::getHP() const
{
	return (HP);
}

int ClapTrap::getEP() const
{
	return (EP);
}

int ClapTrap::getAD() const
{
	return (AD);
}

void ClapTrap::setAD(int val)
{
	AD = val;
	std::cout << Name << "'s Attack Damage is set to " << AD << std::endl;
}
