/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 16:58:47 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/09/04 14:35:06 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

AForm::AForm() :name("unknown"), gradeSign(150), gradeExec(150)
{
	std::cout << "Default Constructor Called." << std::endl;
}

AForm::AForm(std::string givenName, int givenGS, int givenGE) : name(givenName),
	gradeSign(givenGS), gradeExec(givenGE)
{
	if (gradeSign < 1 || gradeExec < 1)
	  throw	GradeTooHighException();
	if (gradeSign > 150 || gradeExec > 150)
	  throw	GradeTooLowException();
	sign = false;
}

AForm::AForm(AForm &other) : name(other.getName()), sign(getSign()), gradeSign(other.getGS()),
	gradeExec(other.getGE()) 
{
	std::cout << "Copy Constructor Called." << std::endl;
}

AForm &AForm::operator=(AForm &other)
{
	if (this != &other)
		sign = other.getSign();
	return (*this);
}

AForm::~AForm()
{
	std::cout << "Destructor of AForm Called." << std::endl;
}

std::string AForm::getName() const
{
	return (name);
}

bool AForm::getSign() const
{
	return (sign);
}

int AForm::getGS() const
{
	return (gradeSign);
}

int AForm::getGE() const
{
	return (gradeExec);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Exception in AForm: Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Exception in AForm: Grade is too low");
}

std::ostream &operator<<(std::ostream &stream, AForm const &node)
{
	stream << "AForm Info" << std::endl;
	stream << "Name: " << node.getName() << std::endl;
	stream << "Status: " << node.getSign() << std::endl;
	stream << "Required grade for sign: " << node.getGS() << std::endl;
	stream << "Required grade for execution: " << node.getGE() << std::endl;
	return (stream);
}

void AForm::beSigned(Bureaucrat &candidate)
{
	if (candidate.getGrade() > this->getGS())
	{
	  throw	GradeTooLowException();
	}
	this->sign = true;
}
