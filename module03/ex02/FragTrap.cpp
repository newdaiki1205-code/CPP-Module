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
