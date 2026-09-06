/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 14:29:37 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/09/06 14:49:11 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"
#include "../include/Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string givenTarget)
  :AForm("PresidentialPardonForm", 25, 5), target(givenTarget)
{
  std::cout << "PresidentialPardonForm Constructed" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
  :AForm("PresidentialPardonForm", 25, 5), target(other.getTarget())
{
  std::cout << "PresidentialPardonForm Copy Constructor Called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
  if(this != &other)
    target = getTarget();
  return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
  std::cout << "PresidentialPardonForm Deconstructed" << std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
  return target;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
  if(!this->getSign())
    throw NotSignedYet();
  executor.executeForm(*this);
  std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
