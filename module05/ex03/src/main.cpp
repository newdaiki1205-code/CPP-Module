/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 15:04:18 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/09/06 15:49:30 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/Intern.hpp"

int	main(void)
{
  try {
    Intern test;
    AForm* rrf;

    rrf = test.makeForm("shrubbery creation", "test");
    std::cout << *rrf << std::endl;
    delete rrf;
  }
  catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  
  std::cout << std::endl;

  try {
    Intern test;
    AForm* rrf;

    rrf = test.makeForm("robotomy request", "test");
    std::cout << *rrf << std::endl;
    delete rrf;
  }
  catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << std::endl;

  try {
    Intern test;
    AForm* rrf;

    rrf = test.makeForm("presidential pardon", "test");
    std::cout << *rrf << std::endl;
    delete rrf;
  }
  catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << std::endl;

  try {
    Intern test;
    AForm* rrf;

    rrf = test.makeForm("noname", "test");
    std::cout << *rrf << std::endl;
    delete rrf;
  }
  catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}

