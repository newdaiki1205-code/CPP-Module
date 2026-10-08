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

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5), target("unknown") {}

PresidentialPardonForm::PresidentialPardonForm(std::string givenTarget)
    : AForm("PresidentialPardonForm", 25, 5), target(givenTarget) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &other)
    : AForm(other), target(other.getTarget()) {}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
  if (this == &other)
    return (*this);
  AForm::operator=(other);
  target = other.getTarget();
  return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

std::string PresidentialPardonForm::getTarget() const { return target; }

void PresidentialPardonForm::executionInPractice() const {
  std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox."
            << std::endl;
}
