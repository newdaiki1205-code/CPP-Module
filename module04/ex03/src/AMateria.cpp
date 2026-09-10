/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42.vienna.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 14:20:51 by dshirais          #+#    #+#             */
/*   Updated: 2026/09/09 14:22:11 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AMateria.hpp"

AMateria::AMateria()
{
  std::cout << "[AMateria] Default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type)
{
  typeValue = type;
  std::cout << "[AMateria] Constructor with parameter called" << std::endl;
}

AMateria::AMateria(const AMateria& other)
{
  std::cout << "[Amateria] Copy Constructor called" << std::endl;
  (void)other;
}

AMateria::~AMateria()
{
  std::cout << "[AMateria] Destructor called" << std::endl;
}

std::string const & AMateria::getType() const
{
  return this->typeValue;
} 

void AMateria::use(ICharacter& target)
{
  (void)target;
  std::cout << "This is virtual dunction and should be implemented in a derived class" << std::endl;
}

