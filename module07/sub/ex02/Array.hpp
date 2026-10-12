/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 14:28:20 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/09/16 15:50:14 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T> class Array {
private:
  T *_array;
  unsigned int _size;

public:
  Array();
  Array(unsigned int n);
  Array(const Array &other);
  Array &operator=(const Array &other);
  const T &operator[](const unsigned int i) const;
  T &operator[](const unsigned int i);
  ~Array();

  class InvalidAccess : public std::exception {
  public:
    const char *what() const throw();
  };
  unsigned int size() const;
};

#include "Array.tpp"

#endif // !ARRAY_HPP
