#include "../include/AMateria.hpp"

AMateria::AMateria(std::string const & type){(void)type;}

AMateria::~AMateria(){}

std::string const & AMateria::getType() const{
  return this->typeValue;
} 

void AMateria::use(ICharacter& target){(void)target;}
