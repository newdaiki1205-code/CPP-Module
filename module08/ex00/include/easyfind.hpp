/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 06:53:22 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/09/23 20:17:35 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <exception>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>

template <typename T>
void easyfind(T container, int target);

class NotFound : public std::exception {};

#include "easyfind.tpp"

#endif // !EASYFIND_HPP
