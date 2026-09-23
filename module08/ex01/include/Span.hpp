/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 15:12:02 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/09/19 11:46:34 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <algorithm>
#include <exception>
#include <iostream>
#include <limits>
#include <iterator>

class Span
{
  private:
    std::vector<int> _container;
    unsigned int _size;

  public:
    Span();
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int n);
    unsigned int longestSpan() const;
    unsigned int shortestSpan() const;

    void show();
    unsigned int getSize();
    void sizeInfo();

    template <typename T>
      void addNumbers(T begin, T end)
      {
        if(static_cast<unsigned int>(std::distance(begin, end)) > _size - _container.size())
          throw ContainerFull();
        T it;
        for(it = begin; it != end; ++it)
          addNumber(*it);
      }

    class ContainerFull :public std::exception
  {
    const char* what() const throw();
  };

    class NoSpan : public std::exception
  {
    const char* what() const throw();
  };
};

#endif // !SPAN_HPP

