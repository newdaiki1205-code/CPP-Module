#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap()
{
    std::cout << "ScavTrap's Constructor called" << std::endl;
    Name = name;
    HP = 100;
    EP =50;
    AD = 30;
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other)
{
    std::cout << "ScavTrap's Copy Constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if(this == &other)
        return (*this);
    Name = other.Name;
    HP = other.HP;
    EP = other.EP;
    AD = other.AD;
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap's Destructor called" << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "Hi, I am " << Name << " ! Let's do high five!" <<std::endl;
}

void FragTrap::attack(std::string& target)
{
    if(!areYouAlive())
    {
        std::cout << "FragTrap " << this->Name << " cannot attack..." << std::endl;
        showStatus();
        return;
    }
    std::cout << "FragTrap " << this->Name << " attacks " << target << " causing " << this->AD << " points of damage!" << std::endl;
    this->EP--;
    std::cout << "FragTrap " << this->Name <<  " has " << this->EP << " EP" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
    if(!areYouAlive())
    {
        std::cout << "FragTrap " << this->Name << " cannot be repaired..." << std::endl;
        showStatus();
        return;
    }
    std::cout << this->Name << " repaired " << amount << "HP!" << std::endl;
    this->HP += amount;
    this->EP--;
    std::cout << this->Name << "'s HP is " << this->HP << std::endl;
}