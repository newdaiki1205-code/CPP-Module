/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42.vienna.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 14:06:00 by dshirais          #+#    #+#             */
/*   Updated: 2026/09/15 14:19:20 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void iter(const T* array, const unsigned int len, void (&f)(const T&))
{
  for(unsigned int i = 0; i < len; i++)
    f(array[i]);
}

template <typename T>
void iter(const T* array, const unsigned int len, void (&f)(T&))
{
  for(unsigned int i = 0; i < len; i++)
    f(array[i]);
}

template <typename T>
void iter(T* array, const unsigned int len, void (&f)(const T&))
{
  for(unsigned int i = 0; i < len; i++)
    f(array[i]);
}

template <typename T>
void iter(T* array, const unsigned int len, void (&f)(T&))
{
  for(unsigned int i = 0; i < len; i++)
    f(array[i]);
}

template <typename T>
void add(T& num)
{
  num += 1;
}

template <typename T>
void show(T& value)
{
  std::cout << value << std::endl;
}

template <typename T>
void show(const T& value)
{
  std::cout << value << std::endl;
}

#endif // !ITER_HPP

