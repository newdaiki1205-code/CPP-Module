/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 13:53:01 by dshirais          #+#    #+#             */
/*   Updated: 2026/09/04 14:24:37 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AFrom.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Bureaucrat;

class RobotomyRequestForm : public AFrom
{
  private:
    std::string target;

  public:
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(RobotomyRequestForm& other);
    ~RobotomyRequestForm();

    void execute(Bureaucrat const &executor);
}

#endif 
