/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 16:58:47 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/09/03 09:32:50 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

Form::Form() :name("unknown"), gradeSign(150), gradeExec(150)
{
	std::cout << "Default Constructor Called." << std::endl;
}

Form::Form(std::string givenName, int givenGS, int givenGE) : name(givenName),
	gradeSign(givenGS), gradeExec(givenGE)
{
	if (gradeSign < 1 || gradeExec < 1)
	  throw	GradeTooHighException();
	if (gradeSign > 150 || gradeExec > 150)
	  throw	GradeTooLowException();
	sign = false;
}

Form::Form(Form &other) : name(other.getName()), sign(getSign()), gradeSign(other.getGS()),
	gradeExec(other.getGE()) 
{
	std::cout << "Copy Constructor Called." << std::endl;
}

Form &Form::operator=(Form &other)
{
	if (this != &other)
		sign = other.getSign();
	return (*this);
}

Form::~Form()
{
	std::cout << "Destructor of Form Called." << std::endl;
}

std::string Form::getName() const
{
	return (name);
}

bool Form::getSign() const
{
	return (sign);
}

int Form::getGS() const
{
	return (gradeSign);
}

int Form::getGE() const
{
	return (gradeExec);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Exception in Form: Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Exception in Form: Grade is too low");
}

std::ostream &operator<<(std::ostream &stream, Form const &node)
{
	stream << "Form Info" << std::endl;
	stream << "Name: " << node.getName() << std::endl;
	stream << "Status: " << node.getSign() << std::endl;
	stream << "Required grade for sign: " << node.getGS() << std::endl;
	stream << "Required grade for execution: " << node.getGE() << std::endl;
	return (stream);
}

void Form::beSigned(Bureaucrat &candidate)
{
	if (candidate.getGrade() > this->getGS())
	{
	  throw	GradeTooLowException();
	}
	this->sign = true;
}
