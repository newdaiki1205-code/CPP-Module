/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42.vienna.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 14:50:01 by dshirais          #+#    #+#             */
/*   Updated: 2026/09/10 14:50:01 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
  stock = new AMateria*[4]();
  for(int i = 0; i < 100; i++)
  {
    this->trash_can[i] = NULL;
  }
}

// MateriaSource::MateriaSource(const AMateria materia){
//   (void)materia;
//   stock = new AMateria*[4]();
// }

MateriaSource::~MateriaSource()
{
  for(int i = 0; i < 4; i++)
  {
    if(stock[i])
      delete stock[i];
  }
  delete [] stock;
  for(int i = 0; i < 100; i++)
  {
    if(this->trash_can[i])
      delete this->trash_can[i];
  }
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
  stock = new AMateria*[4]();
  for(int i = 0; i < 4; i++)
  {
    if(other.stock[i])
      this->stock[i] = other.stock[i];
  }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
  if(this != &other)
  {
    for(int i = 0; i < 4; i++)
    {
      if(stock[i])                  
        delete stock[i];
      stock[i] = other.stock[i];
    }
    for(int i = 0; i < 100; i++)
    {
      if(this->trash_can[i])
        delete this->trash_can[i];
      if(other.trash_can[i])
        this->trash_can[i] = other.trash_can[i];
    }
  }
  return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
{
  for(int i = 0; i < 4; i++)
  {
    if(!stock[i])
    {
      this->stock[i] = m;
      return;
    }
  }
  for(int i = 0; i < 100; i++)
  {
    if(!this->trash_can[i])
    {
      this->trash_can[i] = m;
      break;
    }
  }
}             

AMateria* MateriaSource::createMateria(std::string const & type)
{
  for(int i = 0; i <= 4; i++)
  {
    if(i == 4)
    {
      std::cout << "[MateriaSource] No Materia wiht type: " << type << std::endl;
      return 0;
    }
    if(stock[i] && type == stock[i]->getType())
    {
      std::cout << "[MateriaSource] Created Materia with type: " << type << std::endl; 
      return stock[i]->clone();
    }
  }
  return 0; 
} 

