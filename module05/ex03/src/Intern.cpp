/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 15:05:13 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/09/06 15:43:41 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"

Intern::Intern()
{
  std::cout << "Intern Default Constructor Called" << std::endl;
}

Intern::Intern(const Intern &other)
{
  (void)other;
  std::cout << "Intern Copy Constructor Called" << std::endl;
}

Intern& Intern::operator=(const Intern &other)
{
  (void) other;
  return (*this);
}

Intern::~Intern()
{
  std::cout << "Intern Destructed" << std::endl;
}

const char* Intern::InvalidFormName::what() const throw()
{
  return ("Exception in Intern: Invalid Form Name");
}

AForm* Intern::makeForm(std::string formName, std::string targetForm)
{
  std::string indexArray[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
  int index;

  for(index = 0; index < 3; index++)
  {
    if(!formName.compare(indexArray[index]))
      break;
  }
  switch (index) 
  {
    case 0:
      return new ShrubberyCreationForm(targetForm);
    case 1:
      return new RobotomyRequestForm(targetForm);
    case 2: 
      return new PresidentialPardonForm(targetForm);
    default:
      throw InvalidFormName();
  }
}
