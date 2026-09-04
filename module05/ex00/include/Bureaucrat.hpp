/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 16:31:06 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/09/02 15:12:10 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <iostream>
# include <string>

class Bureaucrat
{
  private:
	const std::string name;
	int grade;

  public:
	Bureaucrat();
	Bureaucrat(std::string givenName, int givenGrade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);

	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};

	std::string getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();
};

std::ostream &operator<<(std::ostream &stream, Bureaucrat const &node);

#endif
