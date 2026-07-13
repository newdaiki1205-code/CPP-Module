#include "Animal.hpp"

/*-----------------------------------------------------------------------*/
/*                      Constructor/Deconstructor                        */
/*-----------------------------------------------------------------------*/


Animal::Animal():type("Base")
{
    std::cout << "Base Constructor called" << std::endl;
};

Animal::Animal(const Animal& other): type(other.type)
{
    std::cout << "Base Copy Constructor called" << std::endl;
};

Animal& Animal::operator=(const Animal& other)
{
    if(this != &other)
        type = other.type;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Base Destructor called" << std::endl;
}

Dog::Dog() : Animal()
{
    type = "Dog";
    std::cout << "Dog Constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) 
{
    std::cout << "Dog Copy Constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if(this != &other)
        type = other.type;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called" << std::endl;
}

Cat::Cat() : Animal()
{
    type = "Cat";
    std::cout << "Cat Constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Cat Copy Constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    if(this != &other)
        type = other.type;
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal():type("WrongBase")
{
    std::cout << "WrongBase Constructor called" << std::endl;
};

WrongAnimal::WrongAnimal(const WrongAnimal& other): type(other.type)
{
    std::cout << "WrongBase Copy Constructor called" << std::endl;
};

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    if(this != &other)
        type = other.type;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongBase Destructor called" << std::endl;
}

WrongCat::WrongCat() : WrongAnimal()
{
    type = "WrongCat";
    std::cout << "WrongCat Constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    std::cout << "WrongCat Copy Constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    if(this != &other)
        type = other.type;
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor called" << std::endl;
}

/*----------------------------------------------------------------------*/
/*                          Member Functions                            */
/*----------------------------------------------------------------------*/

std::string Animal::getType() const
{
    return type;
}

std::string WrongAnimal::getType() const
{
    return type;
}

void Animal::makeSound() const
{
    std::cout << "Base does not make sound" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "BowBow" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meows" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "This is Wrong Sound: Niao" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "MeowsMewos" << std::endl;
}