/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 14:57:51 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/09/06 15:37:16 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "./AForm.hpp"
#include <exception>
#include <string>

class Intern {
public:
  Intern();
  Intern(const Intern &other);
  Intern &operator=(const Intern &other);
  ~Intern();

  AForm *makeForm(std::string formName, std::string targetForm) const;

  class InvalidFormName : public std::exception {
  public:
    virtual const char *what() const throw();
  };
};

#endif
