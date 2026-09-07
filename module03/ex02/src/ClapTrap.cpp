#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap's Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    :Name(name), HP(10), EP(10), AD(0){
        std::cout << "ClapTrap's Constructor called and assigned values" << std::endl;
    }

ClapTrap::ClapTrap(const ClapTrap& other)
    :Name(other.Name), HP(other.HP), EP(other.EP), AD(other.AD){
        std::cout << "Copy Constructor called" << std::endl;
    }

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if(this != &other)
    {
        this->Name = other.Name;
        this->HP = other.HP;
        this->EP = other.EP;
        this->AD = other.AD;
    }
    return (*this);
}       

ClapTrap:: ~ClapTrap(){
    std::cout << "ClapTrap's Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if(!areYouAlive())
    {
        std::cout << "ClapTrap " << this->Name << " cannot attack..." << std::endl;
        showStatus();
        return;
    }
    std::cout << "ClapTrap " << this->Name << " attacks " << target << " causing " << this->AD << " points of damage!" << std::endl;
    this->EP--;
    std::cout << "ClapTrap " << this->Name <<  " has " << this->EP << " EP" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << this->Name << " got " << amount << " damage!" << std::endl;
    for (unsigned int i = 0; i < amount && this->HP > 0; i++)
        this->HP--;
    std::cout << this->Name << "'s HP is " << this->HP << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(!areYouAlive())
    {
        std::cout << "ClapTrap " << this->Name << " cannot be repaired..." << std::endl;
        showStatus();
        return;
    }
    std::cout << this->Name << " repaired " << amount << "HP!" << std::endl;
    this->HP += amount;
    this->EP--;
    std::cout << this->Name << "'s HP is " << this->HP << std::endl;
}

bool ClapTrap::areYouAlive()
{
    if(this->EP > 0 && this->HP > 0)
        return true;
    return false;
}

void ClapTrap::showStatus()
{
    std::cout << this->Name <<" has "
        << this->HP << " HP, "
        << this->EP << " EP."
        << std::endl;
}

int ClapTrap::getAD()
{
    return AD;
}

std::string& ClapTrap::getName()
{
    return Name;
}

void ClapTrap::setName(std::string newName)
{
    Name = newName;
}
