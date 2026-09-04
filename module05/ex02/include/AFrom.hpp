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

#ifndef FORM_HPP
# define FORM_HPP

# include <exception>
# include <iostream>
# include <string>

class Bureaucrat;

class AAform
{
  private:
	const std::string name;
	bool sign;
	const int gradeSign;
	const int gradeExec;

  public:
	Aform();
	Aform(std::string givenName, int givenGS, int givenGE);
	Aform(Aform &other);
	Aform &operator=(Aform &other);
	virtual ~Aform();

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
  virtual void execute(Bureaucrat cpnst &executor);
};

std::ostream &operator<<(std::ostream &stream, Aform const &node);

#endif
