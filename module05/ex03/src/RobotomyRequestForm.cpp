/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 13:00:41 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/09/06 14:14:48 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequest", 72, 45), target("unknown") {}

RobotomyRequestForm::RobotomyRequestForm(std::string givenTarget)
    : AForm("RobotomyRequest", 72, 45), target(givenTarget) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), target(other.getTarget()) {}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
  if (this == &other)
    return (*this);
  AForm::operator=(other);
  target = other.getTarget();
  return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::executionInPractice() const {
  std::cout << "Drrrrrrrrr...Drrrrrrrrr..." << std::endl;
  sleep(1);
  if (rand() % 2)
    std::cout << this->getTarget() << " has been robotomized successfully!"
              << std::endl;
  else
    std::cout << "Robotomization of " << this->getTarget() << " is failed..."
              << std::endl;
}

std::string RobotomyRequestForm::getTarget() const { return target; }
