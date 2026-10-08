/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 15:04:18 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/09/06 14:50:16 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/Intern.hpp"
#include <cstdlib>
#include <ctime>

int main(void) {
  srand(time(0));
  try {
    Intern test;
    AForm *scf;
    Bureaucrat a("a", 1);

    scf = test.makeForm("shrubbery creation", "test");
    std::cout << *scf << std::endl;
    a.signForm(*scf);
    a.executeForm(*scf);
    delete scf;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << std::endl;

  try {
    Intern test;
    AForm *rrf;
    Bureaucrat b("b", 1);

    rrf = test.makeForm("robotomy request", "test");
    std::cout << *rrf << std::endl;
    b.signForm(*rrf);
    b.executeForm(*rrf);
    delete rrf;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << std::endl;

  try {
    Intern test;
    AForm *ppf;
    Bureaucrat c("c", 1);

    ppf = test.makeForm("presidential pardon", "test");
    std::cout << *ppf << std::endl;
    c.signForm(*ppf);
    c.executeForm(*ppf);
    delete ppf;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << std::endl;

  try {
    Intern test;
    AForm *nonExist;

    nonExist = test.makeForm("noname", "test");
    std::cout << *nonExist << std::endl;
    delete nonExist;
  } catch (std::exception &e) {
    std::cout << "Error: " << e.what() << std::endl;
  }
}
