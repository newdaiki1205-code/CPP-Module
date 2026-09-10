/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42.vienna.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 15:03:12 by dshirais          #+#    #+#             */
/*   Updated: 2026/09/09 15:03:12 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cure.hpp"

/*-----------------------------------------------------------------------*/
/*                      Constructor/Deconstructor                        */
/*-----------------------------------------------------------------------*/

Cure::Cure() :AMateria("cure")
{
  std::cout << "[Cure] Default Constructor Called" << std::endl;
}

Cure::~Cure()
{
  std::cout << "[Cure] Destructor Called" << std::endl;

}

Cure::Cure(const Cure& other) :AMateria(other)
{
  std::cout << "[Cure] Copy Constructor Called" << std::endl;
}

Cure& Cure::operator=(const Cure& other)
{
  std::cout << "[Cure] Copy Assignment Operator Called" << std::endl;
    if(this != &other)
        typeValue = other.typeValue;
    return (*this);
}

/*----------------------------------------------------------------------*/
/*                          Member Functions                            */
/*----------------------------------------------------------------------*/

AMateria* Cure::clone() const 
{
    return new Cure();
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

