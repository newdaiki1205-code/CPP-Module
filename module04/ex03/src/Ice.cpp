#include "../include/Ice.hpp"

/*-----------------------------------------------------------------------*/
/*                      Constructor/Deconstructor                        */
/*-----------------------------------------------------------------------*/

Ice::Ice() :AMateria(){typeValue = "ice";}

Ice::Ice(std::string type) : AMateria(type){}

Ice::~Ice(){}

Ice::Ice(const Ice& other) :AMateria(other){}

Ice& Ice::operator=(const Ice& other)
{
    if(this != &other)
        typeValue = other.typeValue;
    return (*this);
}

/*----------------------------------------------------------------------*/
/*                          Member Functions                            */
/*----------------------------------------------------------------------*/

AMateria* Ice::clone() const 
{
    return new Ice("ice");
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << "*" << std::endl;
}
