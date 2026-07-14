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

Dog::Dog() : Animal()
{
    std::cout << "Dog Constructor called" << std::endl;
    type = "Dog";
    idea = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other) 
{
    std::cout << "Dog Copy Constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if(this != &other)
        type = other.type;
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
