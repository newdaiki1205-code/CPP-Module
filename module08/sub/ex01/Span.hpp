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
#define SPAN_HPP

#include <exception>
#include <vector>

class Span {
private:
  std::vector<int> _container;
  unsigned int _size;

public:
  Span();
  Span(unsigned int N);
  Span(const Span &other);
  Span &operator=(const Span &other);
  ~Span();

  void addNumber(int n);
  unsigned int longestSpan() const;
  unsigned int shortestSpan() const;

  void show() const;
  unsigned int getSize() const;
  void sizeInfo() const;

  template <typename T> void addNumbers(T begin, T end) {
    std::vector<int> cpy(begin, end);
    if (cpy.size() > _size - _container.size())
      throw ContainerFull();
    _container.insert(_container.end(), cpy.begin(), cpy.end());
  }

  class ContainerFull : public std::exception {
  public:
    const char *what() const throw();
  };

  class NoSpan : public std::exception {
  public:
    const char *what() const throw();
  };
};

#endif // !SPAN_HPP
