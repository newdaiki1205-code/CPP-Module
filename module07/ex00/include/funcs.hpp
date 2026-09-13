/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 22:00:00 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/09/13 22:09:48 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCS_HPP
# define FUNCS_HPP 

template <typename T>
void swap(T& a, T& b)
{
  T tmp;
  tmp = a;
  a = b;
  b = tmp;
}

template <typename T>
T min(const T& a, const T& b)
{
 if(a == b)
   return b;
 return (a < b ? a : b);
}

template <typename T>
T max(const T& a, const T& b)
{
  if (a == b)
    return b;
  return (a > b ? a : b);
}

#endif

