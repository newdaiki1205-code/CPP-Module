#include "../include/Character.hpp"
#include "../include/AMateria.hpp"

Character::Character(std::string name)
  :name(name)
{
  inventry = new AMateria*[4]();
}

Character::~Character(){
  for(int i = 0; i < 4; i++){
    if(inventry[i])
      delete inventry[i];
  }
  delete[] inventry;
}

Character::Character(const Character& other){
  name = other.name;
  inventry = new AMateria*[4]();
  for(int i = 0; i < 4; i++)
      inventry[i] = other.inventry[i];
}

Character& Character::operator=(const Character& other){
  if(this != &other){
    name = other.name;
    for(int i = 0; i < 4; i++){
      if(inventry[i])                  
        delete inventry[i];
      inventry[i] = other.inventry[i];
    }
  }
  return (*this);
}

std::string const& Character::getName() const {
  return this->name;
}

void Character::equip(AMateria* m) {
  for(int i = 0; i < 4; i++){
    if(!this->inventry[i]){
      this->inventry[i] = m;
      break;
    }
  }
}             

void Character::unequip(int idx){
  if(this->inventry[idx])
    this->inventry[idx] = NULL;
}               

void Character::use(int idx, ICharacter& target){
  if(!this->inventry[idx])
    return;
  this->inventry[idx]->use(target);
  //delete inventry[idx];
} 

