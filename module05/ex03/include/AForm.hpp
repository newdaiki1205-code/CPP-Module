/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AFrom.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 16:34:58 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/09/04 14:35:01 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
# define AForm_HPP

# include <exception>
# include <iostream>
# include <string>

class Bureaucrat;

class AForm
{
  private:
	const std::string name;
	bool sign;
	const int gradeSign;
	const int gradeExec;

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

	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class NotSignedYet : public std::exception
	{
		virtual const char *what() const throw();
	};

	class AlreadySigned : public std::exception
	{
		virtual const char *what() const throw();
	};

	void beSigned(Bureaucrat& candidate);
  virtual void execute(Bureaucrat const &executor) const = 0 ;
};

std::ostream &operator<<(std::ostream &stream, AForm const &node);

#endif
