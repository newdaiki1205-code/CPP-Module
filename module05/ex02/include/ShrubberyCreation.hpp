/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreation.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 13:28:58 by dshirais          #+#    #+#             */
/*   Updated: 2026/09/04 14:49:32 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATION_HPP
# define SHRUBBERYCREATION_HPP

#include "AForm.hpp"
#include <iostream>
#include <string>
#include <fstream>

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
  private:
    std::string target;

  public:
    ShrubberyCreationForm(std::string givenTarget);
    ShrubberyCreationForm(ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(ShrubberyCreationForm& other);
    ~ShrubberyCreationForm();

    std::string getTarget();

    void execute(Bureaucrat const & executor);
};

#endif
