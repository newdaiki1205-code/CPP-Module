/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 13:53:01 by dshirais          #+#    #+#             */
/*   Updated: 2026/09/06 14:20:03 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
  private:
    std::string target;

  public:
    RobotomyRequestForm(std::string givenTarget);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    ~RobotomyRequestForm();

    std::string getTarget() const;

    void execute(Bureaucrat const &executor) const;
};

#endif 
