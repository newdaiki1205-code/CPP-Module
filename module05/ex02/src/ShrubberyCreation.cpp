/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreation.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 14:39:41 by dshirais          #+#    #+#             */
/*   Updated: 2026/09/04 14:57:30 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreation.hpp"
#include "../include/Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string givenTarget)
  :AForm("ShrubberyCreation", 145, 137), target(givenTarget)
{
  std::cout << "ShrubberyCreationForm Constructed" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& other)
  :AForm("ShrubberyCreation", 145, 137), target(other.getTarget())
{
  std..cout << "ShrubberyCreationForm Copy Constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& other)
{
  if(this != &other)
  {
    target = other.getTarget();
  }
  return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
  std::cout << "ShrubberyCreationForm Destructed" << cout::endl;
}

std::string ShrubberyCreationForm::getTarget()
{
  return target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor)
{

}
