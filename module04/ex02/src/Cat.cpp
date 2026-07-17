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


Cat::Cat() : A_Animal()
{
    std::cout << "Cat Constructor called" << std::endl;
    type = "Cat";
    idea = new Brain();
}

Cat::Cat(const Cat& other) : A_Animal(other)
{
    std::cout << "Cat Copy Constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    if(this != &other)
        type = other.type;
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
