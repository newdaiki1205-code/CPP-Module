/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 17:18:30 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/09/04 16:06:27 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Unknown")
{
	std::cout << "Default Constructor Called." << std::endl;
	grade = 150;
}

Bureaucrat::Bureaucrat(std::string givenName, int givenGrade) : name(givenName)
{
	if (givenGrade < 1)
		throw GradeTooHighException();
	if (givenGrade > 150)
		throw GradeTooLowException();
	grade = givenGrade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Deconstrucor Called." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.getName())
{
	grade = other.grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		grade = other.grade;
	return (*this);
}

std::ostream &operator<<(std::ostream &stream, Bureaucrat const &node)
{
	stream << node.getName() << ", bureaucrat grade ";
	stream << node.getGrade() << std::endl;
	return (stream);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Exception: the highest grade is 1.");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Exception: the lowest grade is 150.");
}

std::string Bureaucrat::getName() const
{
	return (name);
}

int Bureaucrat::getGrade() const
{
	return (grade);
}

void Bureaucrat::incrementGrade()
{
	if (grade == 1)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::decrementGrade()
{
	if (grade == 150)
		throw GradeTooLowException();
	grade++;
}


