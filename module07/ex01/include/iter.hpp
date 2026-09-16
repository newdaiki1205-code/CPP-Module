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

template <typename T, typename F>
void iter(T* array, const unsigned int len, void (&f)(F))
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
  std::cout << value << " ";
}

#endif // !ITER_HPP

