/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 15:04:18 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/09/02 15:33:03 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

int	main(void)
{
	std::cout << "Normal Case" << std::endl;
	try
	{
		Bureaucrat test1("test1", 42);
		std::cout << test1;
    Form form1("form1", 42, 42);
    std::cout << form1 << std::endl;
    std::cout << "Try Sign" << std::endl;
    test1.signForm(form1);
    std::cout << form1 << std::endl;
    std::cout << "Try sign again" << std::endl;
    test1.signForm(form1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Exception 1: Bureaucrat does not have enogh grade" << std::endl;
	try
	{
		Bureaucrat test2("test2", 42);
		std::cout << test2;
    Form form2("form2", 1, 42);
		std::cout << form2 << std::endl;
    std::cout << "Try Sign" << std::endl;
    test2.signForm(form2);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
  
	std::cout << "Exception 2: Construct Form with grade 0" << std::endl;
	try
	{
		Bureaucrat test3("test3", 42);
		std::cout << test3;
    Form form3("form3", 0, 42);
		std::cout << form3;
		test3.signForm(form3);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Exception 3: Construct Form with grade 151" << std::endl;
	try
	{
		Bureaucrat test4("test4", 42);
		std::cout << test4;
    Form form4("form4", 151, 42);
		std::cout << form4;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Exception 4: Construct form with grade negative number" << std::endl;
	try
	{
		Bureaucrat test5("test5", 42);
		std::cout << test5;
    Form form5("form5", -1, 42);
		std::cout << form5;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	return (0);
}
