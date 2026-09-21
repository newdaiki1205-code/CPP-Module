/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 15:51:14 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/09/19 11:50:25 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"

Span::Span()
  :_size(0)
{
  std::cout << "Default Constructor called" << std::endl;
}

Span::Span(unsigned int N)
  :_size(N)
{
  std::cout << "Constructor with a parameter called. Container can contain " << N << " numbers."<< std::endl;
}

Span::Span(const Span& other)
{
  std::cout << "Copy Constructor called" << std::endl; 
  _size = other._size;
  _container.assign(other._container.begin(), other._container.end());
}

Span& Span::operator=(const Span& other)
{
  std::cout << "Copy Assignment operator called" << std::endl;
  if(this == &other)
    return (*this);
  _size = other._size;
  _container.clear();
  _container.assign(other._container.begin(), other._container.end());
  return (*this);
}

Span::~Span()
{
  std::cout << "Destructor called" << std::endl;
}

void Span::addNumber(int n)
{
  if(_container.size() == _size)
    throw ContainerFull();
  _container.push_back(n);
}

const char* Span::ContainerFull::what() const throw()
{
  return "Error in adding numbers: No space for given number(s)";
}

unsigned int Span::longestSpan() const
{
  if(_container.size() < 2)
    throw NoSpan();
  return (static_cast<unsigned int>(*std::max_element(_container.begin(), _container.end())) - static_cast<unsigned int>(*std::min_element(_container.begin(), _container.end())));
}

const char* Span::NoSpan::what() const throw()
{
  return "Error in searching span: You should add at least two numbers";
}

unsigned int Span::shortestSpan() const
{
  unsigned int ret = std::numeric_limits<unsigned int>::max();
  unsigned int tmp;
  std::vector<int> vec_cpy(_container);
  std::vector<int>::iterator it;

  if(_container.size() < 2)
    throw NoSpan();
  std::sort(vec_cpy.begin(), vec_cpy.end());
  for(it = vec_cpy.begin(); it + 1 != vec_cpy.end(); ++it)
  {
    tmp = static_cast<unsigned int>(*(it + 1)) - static_cast<unsigned int>(*it);
    if(tmp < ret)
      ret = tmp;
  }
  return ret;
}

void Span::show()
{
  for(size_t i = 0; i < _container.size(); i++)
    std::cout << _container.at(i) << " ";
  std::cout << std::endl;
}

void Span::sizeInfo()
{
  std::cout << "Container size: " << _size << ", Cntainer already has " << _container.size() << " numbers" << std::endl;
}

unsigned int Span::getSize()
{
  return _size;
}

