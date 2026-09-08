/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 08:49:09 by dshirais          #+#    #+#             */
/*   Updated: 2026/07/14 14:57:22 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"


Cat::Cat() : Animal()
{
  std::cout << "Cat Constructor called" << std::endl;
  type = "Cat";
  idea = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other)
{
  std::cout << "Cat Copy Constructor called" << std::endl;
  this->idea = new Brain(*other.idea);
}

Cat& Cat::operator=(const Cat& other)
{
  std::cout << "Cat Coppy Assignment operator called" << std::endl;
  if(this != &other)
  {
    type = other.type;
    delete this->idea;
    this->idea = new Brain(*other.idea);
  }
  return (*this);
}

Cat::~Cat()
{
  delete idea;
  std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound() const
{
  std::cout << "Meows" << std::endl;
}

void Cat::setIdea(std::string idea)
{
  this->idea->setIdea(idea);
}

std::string Cat::getIdea()
{
  return this->idea->getIdea();
}


