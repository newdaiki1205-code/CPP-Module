/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 16:34:58 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/09/02 16:52:20 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <exception>
# include <iostream>
# include <string>

class Bureaucrat;

class Form
{
  private:
	const std::string name;
	bool sign;
	const int gradeSign;
	const int gradeExec;

  public:
	Form();
	Form(std::string givenName, int givenGS, int givenGE);
	Form(Form &other);
	Form &operator=(Form &other);
	~Form();

	std::string getName() const;
	bool getSign() const;
	int getGS() const;
	int getGE() const;

	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};

	void beSigned(Bureaucrat& candidate);
};

std::ostream &operator<<(std::ostream &stream, Form const &node);

#endif
