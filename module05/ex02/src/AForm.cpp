/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 16:58:47 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/09/03 09:32:50 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

AForm::AForm() : name("unknown"), sign(false), gradeSign(150), gradeExec(150) {}

AForm::AForm(std::string givenName, int givenGS, int givenGE)
    : name(givenName), gradeSign(givenGS), gradeExec(givenGE) {
  if (gradeSign < 1 || gradeExec < 1)
    throw GradeTooHighException();
  if (gradeSign > 150 || gradeExec > 150)
    throw GradeTooLowException();
  sign = false;
}

AForm::AForm(const AForm &other)
    : name(other.getName()), sign(other.getSign()), gradeSign(other.getGS()),
      gradeExec(other.getGE()) {}

AForm &AForm::operator=(const AForm &other) {
  if (this != &other)
    sign = other.getSign();
  return (*this);
}

AForm::~AForm() {}

std::string AForm::getName() const { return (name); }

bool AForm::getSign() const { return (sign); }

int AForm::getGS() const { return (gradeSign); }

int AForm::getGE() const { return (gradeExec); }

const char *AForm::GradeTooHighException::what() const throw() {
  return ("the grade is too high.");
}

const char *AForm::GradeTooLowException::what() const throw() {
  return ("the grade is too low.");
}

const char *AForm::AlreadySigned::what() const throw() {
  return ("the form is already signed.");
}

const char *AForm::NotSignedYet::what() const throw() {
  return ("the form is not signed yet.");
}

const char *AForm::FileError::what() const throw() {
  return ("file is not open.");
}
std::ostream &operator<<(std::ostream &stream, AForm const &node) {
  stream << "[Form Info]"
         << " Name: " << node.getName()
         << ", Status: " << (node.getSign() ? "signed" : "not signed")
         << ", Required grade for sign: " << node.getGS()
         << ", Required grade for execution: " << node.getGE();
  return (stream);
}

void AForm::beSigned(const Bureaucrat &candidate) {
  if (this->sign)
    throw AlreadySigned();
  if (candidate.getGrade() > this->getGS()) {
    throw GradeTooLowException();
  }
  this->sign = true;
}

void AForm::execute(const Bureaucrat &executor) const {
  if (!this->sign)
    throw NotSignedYet();
  if (executor.getGrade() > this->getGE())
    throw GradeTooLowException();
  executionInPractice();
}
