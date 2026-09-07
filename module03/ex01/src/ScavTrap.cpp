#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap()
{
    std::cout << "ScavTrap's Default Constructor called" << std::endl;
    Name = name;
    HP = 100;
    EP = 50;
    AD = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap's Copy Constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if(this != &other)
    {
        Name = other.Name;
        HP = other.HP;
        EP = other.EP;
        AD = other.AD;
    }

    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap's Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if(!areYouAlive())
    {
        std::cout << "ScavTrap " << this->Name << " cannot attack..." << std::endl;
        showStatus();
        return;
    }
    std::cout << "ScavTrap " << this->Name << " attacks " << target << " causing " << this->AD << " points of damage!" << std::endl;
    this->EP--;
    std::cout << "ScavTrap " << this->Name <<  " has " << this->EP << " EP" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
    if(!areYouAlive())
    {
        std::cout << "ScavTrap " << this->Name << " cannot be repaired..." << std::endl;
        showStatus();
        return;
    }
    std::cout << this->Name << " repaired " << amount << "HP!" << std::endl;
    this->HP += amount;
    this->EP--;
    std::cout << this->Name << "'s HP is " << this->HP << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gatekeeper mode." << std::endl;
}
