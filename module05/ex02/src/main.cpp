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

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int	main(void)
{
  try {
    Bureaucrat test("test1", 1);
    ShrubberyCreationForm form("target1");
    test.signForm(form);
    form.execute(test);
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << std::endl;

  try {
    Bureaucrat test("test2", 150);
    ShrubberyCreationForm form("target2");
    test.signForm(form);
    form.execute(test);
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << std::endl;
  
  try {
    Bureaucrat test("test3", 145);
    ShrubberyCreationForm form("target3");
    test.signForm(form);
    form.execute(test);
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << std::endl;
  
  try {
    Bureaucrat test("test4", 145);
    ShrubberyCreationForm form("target3");
    form.execute(test);
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << std::endl;

  try {
    Bureaucrat test("test5", 1);
    RobotomyRequestForm form("target5");
    test.signForm(form);
    form.execute(test);
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << std::endl;

  try {
    Bureaucrat test("test6", 150);
    RobotomyRequestForm form("target6");
    test.signForm(form);
    form.execute(test);
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << std::endl;
  
  try {
    Bureaucrat test("test7", 46);
    RobotomyRequestForm form("target7");
    test.signForm(form);
    form.execute(test);
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << std::endl;
  
  try {
    Bureaucrat test("test8", 145);
    RobotomyRequestForm form("target8");
    form.execute(test);
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << std::endl;

  try {
    Bureaucrat test("test9", 1);
    PresidentialPardonForm form("target9");
    test.signForm(form);
    form.execute(test);
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << std::endl;

  try {
    Bureaucrat test("test10", 26);
    PresidentialPardonForm form("target10");
    test.signForm(form);
    form.execute(test);
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << std::endl;
  
  try {
    Bureaucrat test("test11", 6);
    PresidentialPardonForm form("target11");
    test.signForm(form);
    form.execute(test);
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << std::endl;
  
  try {
    Bureaucrat test("test12", 4);
    PresidentialPardonForm form("target12");
    form.execute(test);
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}

