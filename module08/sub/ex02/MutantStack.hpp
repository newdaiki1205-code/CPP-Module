/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 17:13:05 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/09/21 18:05:09 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <deque>
#include <stack>

template <typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
 public:
  MutantStack();
  ~MutantStack();
  MutantStack(const MutantStack& other);
  explicit MutantStack(const Container& cont);
  MutantStack& operator=(const MutantStack& other);

  typedef typename Container::iterator iterator;
  typedef typename Container::reverse_iterator reverse_iterator;
  typedef typename Container::const_iterator const_iterator;
  typedef typename Container::const_reverse_iterator const_reverse_iterator;

  iterator begin();
  iterator end();
  const_iterator begin() const;
  const_iterator end() const;

  reverse_iterator rbegin();
  reverse_iterator rend();
  const_reverse_iterator rbegin() const;
  const_reverse_iterator rend() const;
};

#include "MutantStack.tpp"

#endif  // !MUTANTSTACK_HPP
