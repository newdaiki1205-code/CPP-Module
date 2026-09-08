#include "../include/Animal.hpp"

/*-----------------------------------------------------------------------*/
/*                      Constructor/Deconstructor                        */
/*-----------------------------------------------------------------------*/

Animal::Animal() : type("Base")
{
	std::cout << "Base Constructor called" << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type)
{
	std::cout << "Base Copy Constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
		type = other.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Base Destructor called" << std::endl;
}

/*----------------------------------------------------------------------*/
/*                          Member Functions                            */
/*----------------------------------------------------------------------*/

std::string Animal::getType() const
{
	return (type);
}

void Animal::makeSound() const
{
	std::cout << "Base does not make sound" << std::endl;
}
