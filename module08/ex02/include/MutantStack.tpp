/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 17:24:51 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/09/21 18:06:13 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "./MutantStack.hpp"

template <typename T, class Container>
MutantStack<T, Container>::MutantStack() {}

template <typename T, class Container>
MutantStack<T, Container>::~MutantStack() {}

template <typename T, class Container>
MutantStack<T, Container>::MutantStack(const MutantStack& other)
    : std::stack<T, Container>(other) {}

template <typename T, class Container>
MutantStack<T, Container>::MutantStack(const Container& cont)
    : std::stack<T, Container>(cont) {}

template <typename T, class Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(
    const MutantStack& other) {
  if (this == &other) return *this;
  std::stack<T, Container>::operator=(other);
  return *this;
}

template <typename T, class Container>
typename MutantStack<T, Container>::iterator
MutantStack<T, Container>::begin() {
  return this->c.begin();
}

template <typename T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end() {
  return this->c.end();
}

template <typename T, class Container>
typename MutantStack<T, Container>::const_iterator
MutantStack<T, Container>::begin() const {
  return this->c.begin();
}

template <typename T, class Container>
typename MutantStack<T, Container>::const_iterator
MutantStack<T, Container>::end() const {
  return this->c.end();
}

template <typename T, class Container>
typename MutantStack<T, Container>::reverse_iterator
MutantStack<T, Container>::rbegin() {
  return this->c.rbegin();
}

template <typename T, class Container>
typename MutantStack<T, Container>::reverse_iterator
MutantStack<T, Container>::rend() {
  return this->c.rend();
}

template <typename T, class Container>
typename MutantStack<T, Container>::const_reverse_iterator
MutantStack<T, Container>::rbegin() const {
  return this->c.rbegin();
}

template <typename T, class Container>
typename MutantStack<T, Container>::const_reverse_iterator
MutantStack<T, Container>::rend() const {
  return this->c.rend();
}

#endif
