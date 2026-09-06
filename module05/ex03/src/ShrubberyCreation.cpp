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

#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string givenTarget)
  :AForm("ShrubberyCreation", 145, 137), target(givenTarget)
{
  std::cout << "ShrubberyCreationForm Constructed" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
  :AForm("ShrubberyCreation", 145, 137), target(other.getTarget())
{
  std::cout << "ShrubberyCreationForm Copy Constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
  if(this != &other)
  {
    target = other.getTarget();
  }
  return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
  std::cout << "ShrubberyCreationForm Destructed" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const
{
  return target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
  if(!this->getSign())
    throw NotSignedYet();
  executor.executeForm(*this);
  std::ofstream output((this->getTarget() + "_shrubbery").c_str());
  output << "       _-_" << std::endl;
	output << "    /~~   ~~\\" << std::endl;
	output << " /~~         ~~\\" << std::endl;
	output << "{               }" << std::endl;
	output << " \\  _-     -_  /" << std::endl;
	output << "   ~  \\ //  ~" << std::endl;
	output << "_- -   | | _- _" << std::endl;
	output << "  _ -  | |   -_" << std::endl;
	output << "      // \\\\" << std::endl;
}
