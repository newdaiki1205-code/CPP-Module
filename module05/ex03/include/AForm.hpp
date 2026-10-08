/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 16:34:58 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/09/02 16:52:20 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
private:
  const std::string name;
  bool sign;
  const int gradeSign;
  const int gradeExec;

  virtual void executionInPractice() const = 0;

public:
  AForm();
  AForm(std::string givenName, int givenGS, int givenGE);
  AForm(const AForm &other);
  AForm &operator=(const AForm &other);
  virtual ~AForm();

  std::string getName() const;
  bool getSign() const;
  int getGS() const;
  int getGE() const;

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class AlreadySigned : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class NotSignedYet : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class FileError : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  void beSigned(const Bureaucrat &candidate);
  void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &stream, AForm const &node);

#endif
