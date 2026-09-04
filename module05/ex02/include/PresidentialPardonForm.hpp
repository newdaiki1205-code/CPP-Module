/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 14:25:31 by dshirais          #+#    #+#             */
/*   Updated: 2026/09/04 14:30:34 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PresidentialPardonForm
# define PresidentialPardonForm

#include "AForm.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
  private:
    std::string target;

  public:
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(PresidentialPardonForm& other);
    ~PresidentialPardonForm();

    void execute(Bureaucrat const &executor);
}
#endif 
