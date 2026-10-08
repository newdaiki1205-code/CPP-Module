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
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

int main(void) {
  srand(time(0));
  std::cout << "Test1: execute all forms" << std::endl;
  try {
    Bureaucrat test("test1", 1);
    ShrubberyCreationForm form1("target1");
    RobotomyRequestForm form2("target2");
    PresidentialPardonForm form3("target3");
    std::cout << std::endl;
    std::cout << "=== sign form ===" << std::endl;
    test.signForm(form1);
    test.signForm(form2);
    test.signForm(form3);
    std::cout << std::endl;
    std::cout << "=== execute form ===" << std::endl;
    test.executeForm(form1);
    test.executeForm(form2);
    test.executeForm(form3);
    std::cout << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "------------------------------------------" << std::endl;
  std::cout << "Test2: test with different grade Bureaucrat" << std::endl;
  try {
    Bureaucrat scf("scf", 145);
    Bureaucrat rrf("rrf", 72);
    Bureaucrat ppf("ppf", 25);
    Bureaucrat you("you", 5);
    Bureaucrat arr[4] = {scf, rrf, ppf, you};
    ShrubberyCreationForm form4("test2");
    RobotomyRequestForm form5("test2");
    PresidentialPardonForm form6("test2");
    std::cout << std::endl;
    std::cout << "=== sign form ===" << std::endl;
    for (int i = 0; i < 4; i++) {
      arr[i].signForm(form4);
      arr[i].signForm(form5);
      arr[i].signForm(form6);
      std::cout << std::endl;
    }
    std::cout << "=== execute form ===" << std::endl;
    for (int i = 0; i < 4; i++) {
      arr[i].executeForm(form4);
      arr[i].executeForm(form5);
      arr[i].executeForm(form6);
      std::cout << std::endl;
    }
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "------------------------------------------" << std::endl;
  std::cout << "Test3: execute without sign" << std::endl;
  try {
    Bureaucrat notSigned("notSigned", 1);
    ShrubberyCreationForm form7("test3");
    RobotomyRequestForm form8("test3");
    PresidentialPardonForm form9("test3");
    std::cout << std::endl;
    std::cout << "=== execute form ===" << std::endl;
    notSigned.executeForm(form7);
    notSigned.executeForm(form8);
    notSigned.executeForm(form9);
    std::cout << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "------------------------------------------" << std::endl;
  std::cout << "Test4: copy construction and assignment" << std::endl;
  try {
    Bureaucrat test4("test4", 1);
    ShrubberyCreationForm scfOriginal("scf");
    RobotomyRequestForm rrfOriginal("rrf");
    PresidentialPardonForm ppfOriginal("ppf");

    std::cout << scfOriginal << ", target: " << scfOriginal.getTarget()
              << std::endl;
    std::cout << rrfOriginal << ", target: " << rrfOriginal.getTarget()
              << std::endl;
    std::cout << ppfOriginal << ", target: " << ppfOriginal.getTarget()
              << std::endl;

    std::cout << std::endl;
    ShrubberyCreationForm scfCopy(scfOriginal);
    RobotomyRequestForm rrfCopy(rrfOriginal);
    PresidentialPardonForm ppfCopy(ppfOriginal);

    std::cout << scfCopy << ", target: " << scfCopy.getTarget() << std::endl;
    std::cout << rrfCopy << ", target: " << rrfCopy.getTarget() << std::endl;
    std::cout << ppfCopy << ", target: " << ppfCopy.getTarget() << std::endl;
    std::cout << std::endl;

    ShrubberyCreationForm scfEmpty;
    RobotomyRequestForm rrfEmpty;
    PresidentialPardonForm ppfEmpty;

    std::cout << scfEmpty << ", target: " << scfEmpty.getTarget() << std::endl;
    std::cout << rrfEmpty << ", target: " << rrfEmpty.getTarget() << std::endl;
    std::cout << ppfEmpty << ", target: " << ppfEmpty.getTarget() << std::endl;
    std::cout << std::endl;

    test4.signForm(scfOriginal);
    test4.signForm(rrfOriginal);
    test4.signForm(ppfOriginal);
    std::cout << std::endl;
    scfEmpty = scfOriginal;
    rrfEmpty = rrfOriginal;
    ppfEmpty = ppfOriginal;
    std::cout << scfEmpty << ", target: " << scfEmpty.getTarget() << std::endl;
    std::cout << rrfEmpty << ", target: " << rrfEmpty.getTarget() << std::endl;
    std::cout << ppfEmpty << ", target: " << ppfEmpty.getTarget() << std::endl;

  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}
