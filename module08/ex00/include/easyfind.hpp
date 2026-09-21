/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 06:53:22 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/09/18 08:20:51 by shiraishidais    ###   ########.fr       */
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
