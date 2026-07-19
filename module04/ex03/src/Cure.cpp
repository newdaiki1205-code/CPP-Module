#include "../include/Cure.hpp"

/*-----------------------------------------------------------------------*/
/*                      Constructor/Deconstructor                        */
/*-----------------------------------------------------------------------*/

Cure::Cure(std::string const & type) :AMateria(type){}

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
    return new Cure("Cure");
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
