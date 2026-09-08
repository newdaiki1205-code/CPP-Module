/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 08:46:34 by dshirais          #+#    #+#             */
/*   Updated: 2026/07/14 14:57:48 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog() : A_Animal()
{
  std::cout << "Dog Constructor called" << std::endl;
  type = "Dog";
  idea = new Brain();
}

Dog::Dog(const Dog& other) : A_Animal(other) 
{
  std::cout << "Dog Copy Constructor called" << std::endl;
  this->idea = new Brain(*other.idea);
}

Dog& Dog::operator=(const Dog& other)
{
  std::cout << "Dog Copy Assignement operator called" << std::endl;
  if(this != &other)
  {
    type = other.type;
    delete this->idea;
    this->idea = new Brain(*other.idea);
  }
  return (*this);
}

Dog::~Dog()
{
  delete idea;
  std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound() const
{
  std::cout << "BowBow" << std::endl;
}

void Dog::setIdea(std::string idea)
{
  this->idea->setIdea(idea);
}

std::string Dog::getIdea()
{
  return this->idea->getIdea();
}


