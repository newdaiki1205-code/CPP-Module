#include "../include/Cure.hpp"

/*-----------------------------------------------------------------------*/
/*                      Constructor/Deconstructor                        */
/*-----------------------------------------------------------------------*/

Cure::Cure() :AMateria(){typeValue = "cure";}

Cure::Cure(std::string type) :AMateria(type){}

Cure::~Cure(){}

Cure::Cure(const Cure& other) :AMateria(other){}

Cure& Cure::operator=(const Cure& other)
{
    if(this != &other)
        typeValue = other.typeValue;
    return (*this);
}

/*----------------------------------------------------------------------*/
/*                          Member Functions                            */
/*----------------------------------------------------------------------*/

AMateria* Cure::clone() const 
{
    return new Cure("cure");
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
