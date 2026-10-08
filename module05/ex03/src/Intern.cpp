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
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

Intern::Intern() {
  std::cout << "Intern Default Constructor Called" << std::endl;
}

Intern::Intern(const Intern &other) {
  (void)other;
  std::cout << "Intern Copy Constructor Called" << std::endl;
}

Intern &Intern::operator=(const Intern &other) {
  (void)other;
  return (*this);
}

Intern::~Intern() { std::cout << "Intern Destructed" << std::endl; }

const char *Intern::InvalidFormName::what() const throw() {
  return ("the form name is invalid");
}

static AForm *creationSCF(std::string targetForm) {
  return new ShrubberyCreationForm(targetForm);
}
static AForm *creationRRF(std::string targetForm) {
  return new RobotomyRequestForm(targetForm);
}
static AForm *creationPPF(std::string targetForm) {
  return new PresidentialPardonForm(targetForm);
}

AForm *Intern::makeForm(std::string formName, std::string targetForm) const {
  std::string indexArray[3] = {"shrubbery creation", "robotomy request",
                               "presidential pardon"};
  AForm *(*funArray[3])(std::string) = {&creationSCF, &creationRRF,
                                        &creationPPF};

  for (int i = 0; i < 3; i++) {
    if (!formName.compare(indexArray[i])) {
      std::cout << "Intern creates " << formName << "." << std::endl;
      return funArray[i](targetForm);
    }
  }
  throw InvalidFormName();
}
