/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42.vienna.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 14:51:05 by dshirais          #+#    #+#             */
/*   Updated: 2026/09/09 14:51:05 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Ice.hpp"

/*-----------------------------------------------------------------------*/
/*                      Constructor/Deconstructor                        */
/*-----------------------------------------------------------------------*/

Ice::Ice() :AMateria("ice")
{
  std::cout << "[Ice] Default Constructor called" << std::endl;
}

Ice::~Ice()
{
  std::cout << "[Ice] Destructor called" << std::endl;
}

Ice::Ice(const Ice& other) :AMateria(other)
{
  std::cout << "[Ice] Copy Cpnstructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
    if(this != &other)
        typeValue = other.typeValue;
    return (*this);
}

/*----------------------------------------------------------------------*/
/*                          Member Functions                            */
/*----------------------------------------------------------------------*/

AMateria* Ice::clone() const 
{
    return new Ice();
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << "*" << std::endl;
}

