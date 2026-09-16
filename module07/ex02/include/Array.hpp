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
# define ARRAY_HPP

#include <exception>
#include <iostream>

template <typename T>
class Array
{
  private:
    T* _array;
    unsigned int _size;

  public:
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    Array& operator=(const Array& other);
    ~Array();

    class InvalidAccess : public std::exception{};
    unsigned int size() const;

    void set(T value, unsigned int i);
    T get(unsigned int i);
};

#include "Array.tpp"

#endif // !ARRAY_HPP

