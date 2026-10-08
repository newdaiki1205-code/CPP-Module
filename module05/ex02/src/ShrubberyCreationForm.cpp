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
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreation", 145, 137), target("unknown") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string givenTarget)
    : AForm("ShrubberyCreation", 145, 137), target(givenTarget) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), target(other.getTarget()) {}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
  if (this == &other)
    return (*this);
  AForm::operator=(other);
  target = other.getTarget();
  return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

std::string ShrubberyCreationForm::getTarget() const { return target; }

void ShrubberyCreationForm::executionInPractice() const {
  std::ofstream output((this->getTarget() + "_shrubbery").c_str());
  if (!output)
    throw FileError();
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
