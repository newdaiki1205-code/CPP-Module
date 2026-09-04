/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 15:04:18 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/09/04 16:07:46 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int	main(void)
{
	std::cout << "Normal Case" << std::endl;
	try
	{
		Bureaucrat test1("test1", 42);
		std::cout << test1;
		std::cout << "inclement" << std::endl;
		test1.incrementGrade();
		std::cout << test1;
		std::cout << "declement" << std::endl;
		test1.decrementGrade();
		std::cout << test1;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Exception 1: Increment more than 1" << std::endl;
	try
	{
		Bureaucrat test2("test2", 2);
		std::cout << test2;
		std::cout << "inclement" << std::endl;
		test2.incrementGrade();
		std::cout << test2;
		std::cout << "inclement" << std::endl;
		test2.incrementGrade();
		std::cout << test2;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Exception 2: Decrement more than 150" << std::endl;
	try
	{
		Bureaucrat test3("test3", 149);
		std::cout << test3;
		std::cout << "declement" << std::endl;
		test3.decrementGrade();
		std::cout << test3;
		std::cout << "declement" << std::endl;
		test3.decrementGrade();
		std::cout << test3;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Exception 3: Construct grade 0" << std::endl;
	try
	{
		Bureaucrat test4("test4", 0);
		std::cout << test4;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Exception 4: Construct grade 151" << std::endl;
	try
	{
		Bureaucrat test5("test5", 151);
		std::cout << test5;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Exception 5: Construct grade negative number" << std::endl;
	try
	{
		Bureaucrat test6("test6", -1);
		std::cout << test6;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	return (0);
}
