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
#include "../include/Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string givenTarget)
  :AForm("RobotomyRequest", 72, 45), target(givenTarget)
{
  std::cout << "RobotomyRequestForm Constructed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
  :AForm("RobotomyRequest", 72, 45), target(other.getTarget())
{
  std::cout << "RobotomyRequestForm Copy Constructor called" << std::endl;

}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
  if(this!= &other)
    target = other.getTarget();
  return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
  std::cout << "RobotomyRequestForm Detructed" << std::endl;
}
  
void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
  if(!this->getSign())
    throw NotSignedYet();
  executor.executeForm(*this);
  std::cout << "Drrrrrrrrr...Drrrrrrrrr..." << std::endl;
  sleep(1);
  srand(time(0));
  if(rand() % 2)
    std::cout << this->getTarget() << " has been robotomized successfully!" << std::endl;
  else
    std::cout << "Robotomy is failed..." << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
  return target;
}

