#include "../include/Animal.hpp"

/*-----------------------------------------------------------------------*/
/*                      Constructor/Deconstructor                        */
/*-----------------------------------------------------------------------*/

A_Animal::A_Animal():type("Base")
{
    std::cout << "Base Constructor called" << std::endl;
};

A_Animal::A_Animal(const A_Animal& other): type(other.type)
{
    std::cout << "Base Copy Constructor called" << std::endl;
};

A_Animal& A_Animal::operator=(const A_Animal& other)
{
    if(this != &other)
        type = other.type;
    return (*this);
}

A_Animal::~A_Animal()
{
    std::cout << "Base Destructor called" << std::endl;
}

/*----------------------------------------------------------------------*/
/*                          Member Functions                            */
/*----------------------------------------------------------------------*/

std::string A_Animal::getType() const
{
    return type;
}



void A_Animal::makeSound() const
{
    std::cout << "Base does not make sound" << std::endl;
}
