/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42.vienna.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 15:56:58 by dshirais          #+#    #+#             */
/*   Updated: 2026/09/10 15:07:41 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Character.hpp"
#include "../include/AMateria.hpp"

Character::Character(std::string name)
  :name(name)
{
  std::cout << "[Character] Constructor Called" << std::endl;
  inventry = new AMateria*[4]();
  for(int i = 0; i < 100; i++)
  {
    this->trash_can[i] = NULL;
  }
}

Character::~Character()
{
  std::cout << "[Character] Destructor Called" << std::endl;
  for(int i = 0; i < 4; i++)
  {
    if(inventry[i])
      delete inventry[i];
  }
  for(int i = 0; i < 100; i++)
  {
    if(this->trash_can[i])
      delete trash_can[i];
  }
  delete[] inventry;
}

Character::Character(const Character& other)
{
  std::cout << "[Character] Copy Constructor Called" << std::endl;
  name = other.name;
  inventry = new AMateria*[4]();
  for(int i = 0; i < 4; i++)
      inventry[i] = other.inventry[i];
}

Character& Character::operator=(const Character& other)
{
  if(this != &other)
  {
    name = other.name;
    for(int i = 0; i < 4; i++)
    {
      if(inventry[i])                  
        delete inventry[i];
      inventry[i] = other.inventry[i];
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

std::string const& Character::getName() const 
{
  return this->name;
}

void Character::equip(AMateria* m) 
{
  for(int i = 0; i < 4; i++)
  {
    if(!this->inventry[i])
    {
      std::cout << "Materia equipped in inventry No. " << i << std::endl;
      this->inventry[i] = m;
      return;
    }
  }
  for(int i = 0; i < 100; i++)
  {
    if(!this->trash_can[i])
    {
      this->trash_can[i] = m;
      return;
    }
  }
}             

void Character::unequip(int idx)
{
  if(this->inventry[idx])
  {
    for(int i = 0; i < 100; i++)
    {
      if(!this->trash_can[i])
      {
        this->trash_can[i] = this->inventry[idx];
        break;
      }
    }
    this->inventry[idx] = NULL;
  }
}               

void Character::use(int idx, ICharacter& target)
{
  if(!this->inventry[idx])
    return;
  this->inventry[idx]->use(target);
} 

