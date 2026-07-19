#include "../include/MateriaSource.hpp"

MateriaSource::MateriaSource(){
  stock = new AMateria[4]();
}

MateriaSource::~MateriaSource(){
  delete [] stock;
}

MateriaSource::MateriaSource(const MateriaSource& other){
  stock = new AMateria[4]();
  for(int i = 0; i < 4; i++){
    if(other.stock[i])
      this->stock[i] = other.stock[i];
  }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other){
  if(this != &other){
    for(int i = 0; i < 4; i++){
      if(stock[i])                  
        delete stock[i];
      stock[i] = other.stock[i]
    }
  }
}

void MateriaSource::void learnMateria(AMateria*){
  for(int i = 0; i < 4; i++){
    if(!stock[i]){
      this->stock[i] = m;
      break;
    }
  }
}             

AMateria* MateriaSource::createMateria(std::string const & type){
  for(int i = 0; i < 4; i++){
    if(type == stock[i]->typeValue)
      return stock[i]->clone();
  }
  return 0; 
} 
